#include "Connectable.hxx"

Connectable::Connectable()
{}

Connectable::Connectable(short port, const char *hostname)
{}

Connectable::~Connectable()
{}

/* Reads any incoming messages and then parses them. 
Will process a maximum of mmax messages (used to control how much time
we spend doing network stuff per tick, anything leftover will be done
next tick). Processes messages until none remain if mmax == 0 (there
is a risk of this continuing infinitely if we always recieve a new 
message before we finish processing the old one. */
void Connectable::ReadMessages(uint32_t mmax)
{
    int i, ret;
    if(mmax == 0){
        while(1){
            if(!this->ReadOneMessage())
                return;
        }
    }

    for(i=0; i<mmax; i++){
        if(!this->ReadOneMessage())
            return;
    }
}

/* Process one message from the message buffer. This has no functionality
in the Connectbale class and should be implemented in server / client */
int Connectable::ReadOneMessage()
{
    return -1;
}



/* Reads the least recently recieved message from our listening
    socket and copies it into the message buffer as a messageContainer. */
void Connectable::recieveOneMessage(int socket)
{
    // Read a packet from the UDP socket
    uint8_t bytebuf[MAX_MESSAGE_LENGTH+1];
    struct sockaddr_in src;
    socklen_t s = sizeof(sockaddr_in);
    int bytesRead;

    bytesRead = recvfrom(socket, bytebuf, MAX_MESSAGE_LENGTH, 
    	0, (struct sockaddr *)&src, &s);

    bytebuf[bytesRead] = '\0'; //make it a string

    // Create message struct
    MessageContainer *m = new MessageContainer(src, bytebuf, bytesRead+1);

    //add to the queue
    //log(LOGMEDIUM, "Recieved the message: %s\n", bytebuf);
    this->queue.addMessage(m);

}


/* Creates a new thread which constantly reads the socket and adds
incoming messages to the message buffer. We can't call this until
out socket has been set up.  */
void Connectable::initalizeListeningThread()
{
    pthread_create(&this->t, NULL, listeningDeamon, this);
}




/* A function to be called as the main function of a new thread.
Constantly checks the socket for incoming messages and reads them
into the queue to be processed by the main thread. */
void * listeningDeamon(void *connectable)
{
    /* Stack exchange tells me we don't have to lock the socket
    before reading since concurrent calls to recvfrom and sendto
    are syncronized by the OS since sockets belong to the process
    and not the thread. */

    Connectable * c = (Connectable*)connectable;

    while(1){ // forever
        c->recieveOneMessage(c->getSocket());
    }
}