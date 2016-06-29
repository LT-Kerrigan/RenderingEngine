#pragma once
#include "../nclgl_core/OGLRenderer.h"

enum MeshBuffer { VERTEX_BUFFER, COLOUR_BUFFER, TEXTURE_BUFFER, NORMAL_BUFFER, TANGENT_BUFFER, INDEX_BUFFER, MAX_BUFFER };

class Mesh {
public:
	Mesh();
	~Mesh();

	virtual void Draw();
	static Mesh* GenerateTriangle();
	static Mesh* GenerateQuad();

	void SetTexture(GLuint tex) { m_Texture = tex; }
	GLuint GetTexture() { return m_Texture; }

	void SetBumpMap(GLuint tex)   { bumpTexture = tex; }
	GLuint GetBumpMap()			  { return bumpTexture; }

protected:
	void BufferData();

	void GenerateNormals();

	void GenerateTangents();
	
	Vector3 GenerateTangent(const Vector3 &a, const Vector3 &b,
							const Vector3 &c, const Vector2 &ta,
							const Vector2 &tb, const Vector2 &tc);

	GLuint m_ArrayObject;
	GLuint m_BufferObject[MAX_BUFFER];
	GLuint m_NumVertices;
	GLuint m_Type;

	GLuint m_Texture;
	GLuint bumpTexture;
	Vector2* m_TextureCoords;

	Vector3* m_Vertices;
	Vector4* m_Colours;

	Vector3* m_Normals;
	Vector3* m_Tangents;

	GLuint	m_NumIndices;
	unsigned int* m_Indices;
};