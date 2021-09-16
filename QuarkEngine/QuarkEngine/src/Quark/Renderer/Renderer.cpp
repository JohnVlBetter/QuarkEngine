#include "qkpch.h"
#include "Quark/Renderer/Renderer.h"
#include "Model.h"
#include "Platform/OpenGL/OpenGLShader.h"
#include "Quark/Renderer/Renderer2D.h"

namespace Quark {

	UPtr<Renderer::SceneData> Renderer::mSceneData = CreateUPtr<Renderer::SceneData>();

	void Renderer::Init()
	{
		QK_PROFILE_FUNCTION();
		Model* model = new Model("D:/Workspace/EngineSpace/QuarkEngine/QuarkEngine/Model/nanosuit.obj");
		RenderCommand::Init();
		Renderer2D::Init();
	}

	void Renderer::Shutdown()
	{
		Renderer2D::Shutdown();
	}

	void Renderer::OnWindowResize(uint32_t width, uint32_t height)
	{
		RenderCommand::SetViewport(0, 0, width, height);
	}

	void Renderer::BeginScene(OrthographicCamera& camera)
	{
		mSceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void Renderer::EndScene()
	{
	}

	void Renderer::Submit(const SPtr<Shader>& shader, const SPtr<VertexArray>& vertexArray, const glm::mat4& transform)
	{
		shader->Bind();
		shader->SetMat4("u_ViewProjection", mSceneData->ViewProjectionMatrix);
		shader->SetMat4("u_Transform", transform);

		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}

}
