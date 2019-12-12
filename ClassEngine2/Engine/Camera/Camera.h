#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

#include "../FX/LightSource.h"

enum FrustumPlanes {
	RIGHT = 0,		// RIGHT side of the frustum
	LEFT = 1,		// LEFT side of the frustum
	BOTTOM = 2,		// BOTTOM side of the frustum
	TOP = 3,		// TOP side of the frustum
	FRONT = 4,		// BACK side of the frustum
	BACK = 5		// FRONT side of the frustum
};

enum PlaneData {
	NX = 0,			// X value of normal plane
	NY = 1,			// Y value of normal plane
	NZ = 2,			// Z value of normal plane
	NO = 3			// The distance the plane is from the origin
};

class Camera {
public:
	Camera();
	~Camera();
	void SetPosition(glm::vec3 position_); // Camera actual position
	void SetRotation(float yaw_, float pitch_, float roll_); // Setters for camera rotation
	void AddLightSource(LightSource* lightSource_); // This function is to take lightSource constructor as pointer
	glm::mat4 GetView() const; // Setting View Matrix
	const glm::mat4 GetPerspective(); // 3D perspective view
	const glm::mat4 GetOrthographic(); // 2D Orthographic view
	inline glm::vec3 GetPosition() const { return position; } // Getters for camera position, in order to get Mesh's shader uniform
	inline std::vector<LightSource*> GetLightSources() const { return subLightSource; } // LightSource vector to push_back
	inline glm::vec2 GetClippingPlanes() const { return glm::vec2(nearPlane, farPlane); } // Clipping planes to rayCast

	void ProcessMouseMovement(float xOffset_, float yOffset_); // This is EventHandler function to mouse movement
	void ProcessMouseZoom(int y_); // EventHandler function to Mouse scroll to zoom in and out 

	void NormalizePlane(float frustum_[6][4], int side_); // Frustum plane normalize for camera view
	void CalculateFrustum(); // Call this every time the camera moves to update the frustum
	bool PointInFrustum(glm::vec3 modelPosition_); // This takes a 3D point and returns TRUE if it's inside of the frustum

private:
	void UpdateCameraVectors(); // Camera Update Vector function
	void OnDestroy();

	glm::vec3 position;
	glm::mat4 perspective, orthographic;
	float yaw, pitch, roll;
	float fieldOfView;
	float nearPlane, farPlane;
	glm::vec3 forwardVector, upVector, rightVector, worldUp;
	std::vector<LightSource*> subLightSource; // 2019-10-15

	float frustums[6][4]; // This holds the NX NY NZ and NO values for each side of our frustum.
	glm::mat4 proj, view, clip; // This will hold our projection, view matrix, and clipping planes.


};
#endif