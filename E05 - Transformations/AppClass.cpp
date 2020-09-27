#include "AppClass.h"
void Application::InitVariables(void)
{
	//Make MyMesh object
	m_pMesh1 = new MyMesh();
	m_pMesh1->GenerateCube(1.0f, C_WHITE);

	newX = 0.0f;

	// Generate the space invader out of cubes, as directed in the exercise.
	spaceInvaderMeshes = new vector<MyMesh*>();

	for (int i = 0; i < 46; i++) 
	{
		MyMesh* nextCube = new MyMesh();
		nextCube->GenerateCube(1.0f, C_PURPLE);
		spaceInvaderMeshes->push_back(nextCube);
	}
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	//m_pMesh->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), ToMatrix4(m_qArcBall));
	//m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3( -2.0f, 0.0f, 0.0f)));

	// Render all the spaceInvader cube meshes.
	RenderSpaceInvader(newX);

	// Move the space invader meshes to the right a bit.
	newX += 0.1f;

	// draw a skybox
	m_pMeshMngr->AddSkyboxToRenderList();
	
	//render list call
	m_uRenderCallCount = m_pMeshMngr->Render();

	//clear the render list
	m_pMeshMngr->ClearRenderList();
	
	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::RenderSpaceInvader(int newX)
{
	MyMesh* currentCube;
	// Just go through and render each cube with its own line because I've given up on pretenses of fanciness at this point.

	// Do the -5.0f column.
	currentCube = spaceInvaderMeshes->at(0);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-5.0f + newX, 0.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(1);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-5.0f + newX, -1.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(2);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-5.0f + newX, -2.0f, 0.0f)));

	// Do the -4.0f column.
	currentCube = spaceInvaderMeshes->at(3);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-4.0f + newX, 1.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(4);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-4.0f + newX, 0.0f, 0.0f)));

	// Do the -3.0f column.
	currentCube = spaceInvaderMeshes->at(5);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-3.0f + newX, 4.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(6);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-3.0f + newX, 2.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(7);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-3.0f + newX, 1.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(8);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-3.0f + newX, 0.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(9);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-3.0f + newX, -1.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(10);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-3.0f + newX, -2.0f, 0.0f)));

	// Do the -2.0f column.
	currentCube = spaceInvaderMeshes->at(11);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-2.0f + newX, 3.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(12);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-2.0f + newX, 2.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(13);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-2.0f + newX, 0.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(14);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-2.0f + newX, -1.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(15);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-2.0f + newX, -3.0f, 0.0f)));

	// Do the -1.0f column.
	currentCube = spaceInvaderMeshes->at(16);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-1.0f + newX, 2.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(17);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-1.0f + newX, 1.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(18);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-1.0f + newX, 0.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(19);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-1.0f + newX, -1.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(20);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-1.0f + newX, -3.0f, 0.0f)));

	// Do the 0.0f column.
	currentCube = spaceInvaderMeshes->at(21);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(0.0f + newX, 2.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(22);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-0.0f + newX, 1.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(23);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-0.0f + newX, 0.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(24);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(-0.0f + newX, -1.0f, 0.0f)));

	// Do the 1.0f column.
	currentCube = spaceInvaderMeshes->at(25);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(1.0f + newX, 2.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(26);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(1.0f + newX, 1.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(27);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(1.0f + newX, 0.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(28);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(1.0f + newX, -1.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(29);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(1.0f + newX, -3.0f, 0.0f)));

	// Do the 2.0f column.
	currentCube = spaceInvaderMeshes->at(30);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(2.0f + newX, 3.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(31);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(2.0f + newX, 2.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(32);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(2.0f + newX, 0.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(33);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(2.0f + newX, -1.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(34);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(2.0f + newX, -3.0f, 0.0f)));

	// Do the 3.0f column.
	currentCube = spaceInvaderMeshes->at(35);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(3.0f + newX, 4.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(36);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(3.0f + newX, 2.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(37);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(3.0f + newX, 1.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(38);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(3.0f + newX, 0.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(39);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(3.0f + newX, -1.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(40);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(3.0f + newX, -2.0f, 0.0f)));

	// Do the 4.0f column.
	currentCube = spaceInvaderMeshes->at(41);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(4.0f + newX, 1.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(42);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(4.0f + newX, 0.0f, 0.0f)));

	// Do the 5.0f column.
	currentCube = spaceInvaderMeshes->at(43);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(5.0f + newX, 0.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(44);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(5.0f + newX, -1.0f, 0.0f)));

	currentCube = spaceInvaderMeshes->at(45);
	currentCube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3(5.0f + newX, -2.0f, 0.0f)));
}
void Application::Release(void)
{
	if (m_pMesh != nullptr)
	{
		delete m_pMesh;
		m_pMesh = nullptr;
	}

	delete[] spaceInvaderMeshes;

	SafeDelete(m_pMesh1);
	//release GUI
	ShutdownGUI();
}