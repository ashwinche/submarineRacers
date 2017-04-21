#include "mesh.hxx"
#include <obj/obj-reader.hxx>

/*! The locations of the standard mesh attributes.  The layout directives in the shaders
 * should match these values.
 */
const GLint CoordAttrLoc = 0;   //!< location of vertex coordinates attribute
const GLint NormAttrLoc = 1;
const GLint TexCoordAttrLoc = 2;

//! create a MeshInfo object by initializing its buffer Ids.  The buffer data is
//! loaded separately.
Mesh::Mesh(GLenum p) {
  data.vbufId=0;
  data.ibufId=0;
  data.prim=p;
  data.nIndicies=0;
  data.color=vec4 (1,1,1,0.5f);
  data.shouldTexture = 0;

  data.polygon_mode=GL_FILL;
  data.visible=1;
  data.owner = this;

  glGenVertexArrays(1, &data.vaoId);
}

Mesh::Mesh(const Mesh &copyfrom){
  data = copyfrom.data;
}

//! initialize the vertex data buffers for the mesh
void Mesh::loadVertices (int nVerts, const vec3 *verts)
{
    glBindVertexArray(data.vaoId);
    glGenBuffers(1, &data.vbufId);
    glBindBuffer(GL_ARRAY_BUFFER, data.vbufId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vec3)*nVerts, verts, GL_STATIC_DRAW);
    glVertexAttribPointer(CoordAttrLoc, 3, GL_FLOAT, GL_FALSE, sizeof(verts[0]), (GLvoid *)0);
    glEnableVertexAttribArray(CoordAttrLoc);
}

//! initialize the element array for the mesh
void Mesh::loadIndices (int n, const uint32_t *indices)
{
    data.nIndicies = n; 
    glBindVertexArray (data.vaoId);
    glGenBuffers (1, &data.ibufId);
    glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, data.ibufId);
    glBufferData (GL_ELEMENT_ARRAY_BUFFER, n*sizeof(uint32_t), indices, GL_STATIC_DRAW); //might be STATIC_DRAW
    glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, 0);
    glEnableVertexAttribArray(CoordAttrLoc);
}

void Mesh::LoadTexCoords (int nCoords, vec2 *tcoords){
  data.nTexCoords = nCoords;
  glBindVertexArray (data.vaoId);
  glGenBuffers (1, &data.tbufId);
  glBindBuffer (GL_ARRAY_BUFFER, data.tbufId);
  glBufferData (GL_ARRAY_BUFFER, nCoords*sizeof(vec2), tcoords, GL_STATIC_DRAW);
  glVertexAttribPointer(TexCoordAttrLoc, 2, GL_FLOAT, GL_FALSE, sizeof(tcoords[0]), (GLvoid *)0);
  glEnableVertexAttribArray(TexCoordAttrLoc);
}

//! initalize the vertex array for the normals
void Mesh::loadNormals (int nVerts, vec3 *norms){
  glBindVertexArray (data.vaoId);
  glGenBuffers (1, &data.nbufId);
  glBindBuffer (GL_ARRAY_BUFFER, data.nbufId);
  glBufferData (GL_ARRAY_BUFFER, nVerts*sizeof(vec3), norms, GL_STATIC_DRAW);
  glVertexAttribPointer(NormAttrLoc, 3, GL_FLOAT, GL_FALSE, sizeof(vec3), ((GLvoid*) 0));
  glEnableVertexAttribArray(NormAttrLoc);
}

void Mesh::draw ()
{
    glBindVertexArray(data.vaoId);
    glBindBuffer(GL_ARRAY_BUFFER, data.vbufId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, data.ibufId);

    glDrawElements (data.prim, data.nIndicies, GL_UNSIGNED_INT, 0);

}

void Mesh::loadOBJ(char *file){
  data.prim = GL_TRIANGLES;
  data.shouldTexture = false;  // change.
  data.color = vec4(1.f,1.f,1.f,1.f);

  OBJmodel *model = OBJReadOBJ (file);

  vec3 *verts = new vec3[model->numtriangles*3];
  vec3 *norms = new vec3[model->numtriangles*3];
  vec2 *texcs = new vec2[model->numtriangles*3];

  // indices. for our purposes, it is {0,1,2, 3,4,5, ... n*3};
  unsigned int *indices =new unsigned int[model->numtriangles*3];
  for(int i=0;i<model->numtriangles*3;++i){
    indices[i]=i;
  }

  OBJgroup *gp = model->groups;

  int ind=0;
  while(gp != 0){
    for(int i=0;i<gp->numtriangles;++i){
      OBJtriangle &tri = model->triangles[gp->triangles[i]];
      verts[ind+0]=model->vertices[tri.vindices[0]];
      verts[ind+1]=model->vertices[tri.vindices[1]];
      verts[ind+2]=model->vertices[tri.vindices[2]];

      // printf("triangle with %d %d %d\n",tri.vindices[0],tri.vindices[1],tri.vindices[2]);
      // printf("triangle starting (%.3f,%.3f,%.3f)\n",verts[ind].x,verts[ind].y,verts[ind].z);

      norms[ind+0]=model->normals[tri.nindices[0]];
      norms[ind+1]=model->normals[tri.nindices[1]];
      norms[ind+2]=model->normals[tri.nindices[2]];

      // texcs[ind+0]=model->texcoords[tri.tindices[0]];
      // texcs[ind+1]=model->texcoords[tri.tindices[1]];
      // texcs[ind+2]=model->texcoords[tri.tindices[2]];

      ind+=3;
    }
    gp = gp->next;
  }

  loadNormals(model->numtriangles*3, norms);
  LoadTexCoords(model->numtriangles*3, texcs);
  loadVertices(model->numtriangles*3, verts);
  loadIndices(model->numtriangles*3, indices);
}