#include "renderer.h"

#include "GLFW/glfw3.h"
#include <OpenGL/gl.h>
#include <tools/model.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include <tools/filesystem.h>
#include <tools/loadtexture.h>
#include <tools/shader.h>

namespace Graphics {
Shader *lightingShader;
Shader *lightingShader2;
Shader *depthShader;
Shader *outlineShader;
// Shader *lightCubeShader;

glm::vec3 pointLightPositions[] = {
    glm::vec3(0.7f, 0.2f, 2.0f),
    glm::vec3(2.3f, -3.3f, -4.0f),
    glm::vec3(-4.0f, 2.0f, -12.0f),
    glm::vec3(0.0f, 0.2f, -3.0f),
};
Model ourModel;

bool Init() {
	// Setup OpenGL state: shaders, buffers, etc.
	// e.g., load shaders, setup framebuffers, etc.
	// tell stb_image.h to flip loaded texture's on the y-axis (before loading
	// model).
	stbi_set_flip_vertically_on_load(true);

	// Depth
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	// Stencil
	// glEnable(GL_STENCIL_TEST);
	// Blending
	glEnable(GL_BLEND);
	// Culling
	glEnable(GL_CULL_FACE);

	// -- Build and compile the shader program --
	lightingShader = new Shader("../shaders/shader.vs", "../shaders/shader.fs");
	lightingShader2 =
	    new Shader("../shaders/shader.vs", "../shaders/shader.fs");
	depthShader =
	    new Shader("../shaders/depthShader.vs", "../shaders/depthShader.fs");
	outlineShader =
	    new Shader("../shaders/depthShader.vs", "../shaders/outlineShader.fs");
	// lightCubeShader =
	//     new Shader("../shaders/lightShader.vs", "../shaders/lightShader.fs");

	// load models
	// -----------
	ourModel =
	    Model(FileSystem::getPath("game/assets/objects/backpack/backpack.obj"));

	// uncomment this call to draw in wireframe polygons.
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	return true;
}

void Render(const Camera &camera) {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_STENCIL_TEST);
	// Clear previous render
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
	// lightColor.x = sin(glfwGetTime() * 2.0f);
	// lightColor.y = sin(glfwGetTime() * 0.7f);
	// lightColor.z = sin(glfwGetTime() * 1.3f);
	// directional light
	lightingShader->setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
	lightingShader->setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
	lightingShader->setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
	lightingShader->setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
	// point light 1
	lightingShader->setVec3("pointLights[0].position", pointLightPositions[0]);
	lightingShader->setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
	lightingShader->setVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
	lightingShader->setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
	lightingShader->setFloat("pointLights[0].constant", 1.0f);
	lightingShader->setFloat("pointLights[0].linear", 0.09f);
	lightingShader->setFloat("pointLights[0].quadratic", 0.032f);
	// point light 2
	lightingShader->setVec3("pointLights[1].position", pointLightPositions[1]);
	lightingShader->setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
	lightingShader->setVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
	lightingShader->setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
	lightingShader->setFloat("pointLights[1].constant", 1.0f);
	lightingShader->setFloat("pointLights[1].linear", 0.09f);
	lightingShader->setFloat("pointLights[1].quadratic", 0.032f);
	// point light 3
	lightingShader->setVec3("pointLights[2].position", pointLightPositions[2]);
	lightingShader->setVec3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
	lightingShader->setVec3("pointLights[2].diffuse", 0.8f, 0.8f, 0.8f);
	lightingShader->setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
	lightingShader->setFloat("pointLights[2].constant", 1.0f);
	lightingShader->setFloat("pointLights[2].linear", 0.09f);
	lightingShader->setFloat("pointLights[2].quadratic", 0.032f);
	// point light 4
	lightingShader->setVec3("pointLights[3].position", pointLightPositions[3]);
	lightingShader->setVec3("pointLights[3].ambient", 0.05f, 0.05f, 0.05f);
	lightingShader->setVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
	lightingShader->setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
	lightingShader->setFloat("pointLights[3].constant", 1.0f);
	lightingShader->setFloat("pointLights[3].linear", 0.09f);
	lightingShader->setFloat("pointLights[3].quadratic", 0.032f);
	// spotLight
	lightingShader->setVec3("spotLight.position", camera.position);
	lightingShader->setVec3("spotLight.direction", camera.front);
	lightingShader->setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
	lightingShader->setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
	lightingShader->setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
	lightingShader->setFloat("spotLight.constant", 1.0f);
	lightingShader->setFloat("spotLight.linear", 0.09f);
	lightingShader->setFloat("spotLight.quadratic", 0.032f);
	lightingShader->setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
	lightingShader->setFloat("spotLight.outerCutOff",
	                         glm::cos(glm::radians(15.0f)));

	// Projection matrix
	glm::mat4 projection = glm::perspective(glm::radians(camera.fov),
	                                        1280.0f / 720.0f, 0.1f, 100.0f);
	glm::mat4 view = camera.getViewMatrix();

	// render the loaded model
	glm::mat4 model = glm::mat4(1.0f);
	// translate it down so it's at the center of the scene
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
	// it's a bit too big for our scene, so scale it down
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));

	// --- Draw ---
	// Draw object
	glStencilFunc(GL_ALWAYS, 1, 0xFF); // Set stencil to 1 where rendered
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	glStencilMask(0xFF); // Enable writing to stencil buffer
	glDepthMask(GL_TRUE);
	glEnable(GL_DEPTH_TEST);
	lightingShader->use();
	// lightingShader->setVec3("viewPos", camera.position);
	lightingShader->setMat4("projection", projection);
	lightingShader->setMat4("view", view);
	glm::mat4 normalModel = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f));
	normalModel = glm::scale(normalModel, glm::vec3(1.0f));
	lightingShader->setMat4("model", normalModel);
	ourModel.Draw(lightingShader);

	// Draw outline
	// glStencilFunc(GL_NOTEQUAL, 1, 0xFF); // Only draw where stencil is not 1
	// glStencilMask(0x00);                 // Disable writing to stencil buffer
	// glDisable(GL_DEPTH_TEST);            // Optional: avoid z-fighting
	// outlineShader->use();
	// outlineShader->setMat4("projection", projection);
	// outlineShader->setMat4("view", view);
	// glm::mat4 outlineModel = glm::translate(glm::mat4(1.0f),
	// glm::vec3(0.0f)); outlineModel =
	//     glm::scale(outlineModel, glm::vec3(1.05f)); // Slightly larger
	// outlineShader->setMat4("model", outlineModel);
	// ourModel.Draw(outlineShader);
	//
	// // Reset after outline draw
	glEnable(GL_DEPTH_TEST);
	glStencilMask(0xFF);
	glStencilFunc(GL_ALWAYS, 1, 0xFF);
	glDepthMask(GL_TRUE);

	// lightingShader2->use();
	// // lightingShader->setVec3("viewPos", camera.position);
	// lightingShader2->setMat4("projection", projection);
	// lightingShader2->setMat4("view", view);
	// normalModel = glm::translate(glm::mat4(3.0f), glm::vec3(0.0f));
	// normalModel = glm::scale(normalModel, glm::vec3(1.0f));
	// lightingShader2->setMat4("model", normalModel);
	// ourModel.Draw(lightingShader2);

	//////// LIGHT CUBE ///////////
	// Render the lamp object lightCubeShader->use();
	// lightCubeShader->use();
	// lightCubeShader->setMat4("projection", projection);
	// lightCubeShader->setMat4("view", view);
	// lightCubeShader->setVec3("lightColor", lightColor);
	// for (unsigned int i = 0; i < 4; i++) {
	// 	model = glm::mat4(1.0f);
	// 	model = glm::translate(model, pointLightPositions[i]);
	// 	model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
	// 	lightCubeShader->setMat4("model", model);
	// 	// glDrawArrays(GL_TRIANGLES, 0, 36);
	// 	ourModel.Draw(lightCubeShader);
	// }
}

void Shutdown() {
	// Cleanup OpenGL resources
}

} // namespace Graphics
