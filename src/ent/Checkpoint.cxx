#include "Checkpoint.hxx"

/* Constuct a regular hexagon at the given center with the given radius,
with a normal facing down the z-axis */
Hexagon::Hexagon(vec3 center, float r)
{
	this->Lt = r*vec3(-0.866,0.5,0)+center;
	this->Lb = r*vec3(-0.866,-0.5,0)+center;
	this->Mt = r*vec3(0,1,0)+center;
	this->Mb = r*vec3(0,-1,0)+center;
	this->Rt = r*vec3(0.866,0.5,0)+center;
	this->Rb = r*vec3(0.866,-0.5,0)+center;

	this->center = center;
	this->normal = vec3(0,0,1);

}

/* Construct a hexagon using the 6 corner points */
Hexagon::Hexagon(vec3 Lt, vec3 Lb, vec3 Mt, vec3 Mb, vec3 Rt, vec3 Rb)
{
	this->Lt = Lt; this->Lb = Lb; this->Mt = Mt; this->Mb = Mb;
	this->Rt = Rt; this->Rb = Rb;

	this->center = (Lt + Lb + Mt + Mb + Rt + Rb) / 6.0f;
	this->normal = normalize(cross(normalize(Lt - this->center),
		normalize(Lb - this->center)));
}

/* Translate a point by distance along the given axis */
vec3 displace(vec3 point, vec3 axis, float displace)
{
	vec3 result = point + (axis * displace);
	return result;
}

/* Return a mesh representation of the hexagon as a hexagonal
prism with the given length. */
Mesh* Hexagon::getMesh(float length)
{

	/* Use of the "this" keyword omitted for clarity */

	/* Iinitalize Vertex and Index array for flat hex */
	int nVecs = 14;
	vec3 *v = (vec3*)malloc(nVecs*sizeof(vec3));
	v[0] = displace(center, normal, length);
	v[1] = displace(Lt, normal, length);
	v[2] = displace(Mt, normal, length);
	v[3] = displace(Rt, normal, length);
	v[4] = displace(Rb, normal, length);
	v[5] = displace(Mb, normal, length);
	v[6] = displace(Lb, normal, length);
	v[7] = displace(center, normal, -length);
	v[8] = displace(Lt, normal, -length);
	v[9] = displace(Mt, normal, -length);
	v[10] = displace(Rt, normal, -length);
	v[11] = displace(Rb, normal, -length);
	v[12] = displace(Mb, normal, -length);
	v[13] = displace(Lb, normal, -length);

	int j, nIndices = 96;
	uint32_t stack_i[nIndices] = 
	{2,1,0,  3,2,0,   4,3,0,   5,4,0,   6,5,0,   1,6,0,  //front face
	 7,8,9,  7,9,10,  7,10,11, 7,11,12, 7,12,13, 7,13,8, //back face
	 1,9,2,  2,9,10,  2,10,3,  3,10,11, 3,11,4,  4,11,12, //sides
	 4,12,5, 5,12,6,  6,12,13, 6,13,8,  6,8,1,   1,8,9};

	uint32_t *i = (uint32_t*)malloc(nIndices*sizeof(uint32_t));
	for(j=0; j<nIndices; j++)
		i[j] = stack_i[j];

	// Create the mesh
	Mesh *m = new Mesh(GL_TRIANGLES);
    m->loadVertices (nVecs, v);
    m->loadIndices (nIndices, i);

    return m;
}


Checkpoint::Checkpoint(int ID, vec3 initial_position, quaternion initial_orientation,
        std::string name, EntityType type, EntityStatus status, float tick_interval)
:Entity(ID, initial_position, initial_orientation, name, type, status, tick_interval)
{ }

Checkpoint::~Checkpoint() { }


FinishLine::FinishLine(int ID, vec3 initial_position, quaternion initial_orientation,
        std::string name, EntityType type, EntityStatus status, float tick_interval)
:Checkpoint(ID, initial_position, initial_orientation, name, type, status, tick_interval)
{ }

FinishLine::~FinishLine() { }


SeekPoint::SeekPoint(int ID, vec3 initial_position, quaternion initial_orientation,
	    std::string name, EntityType type, EntityStatus status, float tick_interval,
	    Hexagon *hex)
:Entity(ID, initial_position, initial_orientation, name, type, status, tick_interval)
{

	/* TODO: check if hex is valid */
	this->hex = hex;

	this->initalizeVisualData();
}

SeekPoint::~SeekPoint() 
{
	delete(this->hex);
};


void SeekPoint::initalizeVisualData(){
	this->initalizeTextures("../assets/textures/cubetex.png");
	this->initalizeMeshes();
}

void SeekPoint::initalizeMeshes()
{
    Mesh *mesh = this->hex->getMesh(0.2);
    //Mesh *mesh = new Mesh(GL_TRIANGLES);
    //mesh->loadOBJ("../assets/models/cube.obj");
    vec3 col = vec3(1.0f, 0.5f, 0.5f);
    mesh->data.color = vec4(col, 1.0); // transparent pink
    mesh->data.tex = this->tex;
    this->meshes.push_back(TransformedMesh(TransformedMesh::MeshInfo(mesh,mat4(1))));
}

void SeekPoint::initalizeTextures(const char* texfile)
{
	//load texture
    image2d * image = new image2d(texfile, true);
    texture2d * cubetex = new texture2d(GL_TEXTURE_2D, image);
    this->tex = cubetex;
    this->img = image;
}


vec3 SeekPoint::getCenter()
{
	return this->hex->center;
}