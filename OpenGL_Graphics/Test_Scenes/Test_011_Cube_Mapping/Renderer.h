#pragma once

#include <OGLRenderer.h>
#include <Camera.h>
#include <HeightMap.h>

class Renderer : public OGLRenderer {
public:
	Renderer(Window &parent);
	virtual ~Renderer(void);

	virtual void RenderScene();
	virtual void UpdateScene(float msec);

protected:
	void DrawHeightMap();
	void DrawWater();
	void DrawSkybox();

	Shader*	lightShader;
	Shader* reflectShader;
	Shader* skyboxShader;

	HeightMap* heightMap;
	Mesh*	   quad;
	
	Light*  light;
	Camera* camera;

	GLuint cubeMap;
	float waterRotate;
};