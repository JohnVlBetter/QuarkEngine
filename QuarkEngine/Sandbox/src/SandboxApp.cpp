#include <Quark.h>

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>

class ExampleLayer : public Quark::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), mCamera(-1.6f, 1.6f, -0.9f, 0.9f), mCameraPosition(0.0f)
	{
		mVertexArray.reset(Quark::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		std::shared_ptr<Quark::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Quark::VertexBuffer::Create(vertices, sizeof(vertices)));
		Quark::BufferLayout layout = {
			{ Quark::ShaderDataType::Float3, "a_Position" },
			{ Quark::ShaderDataType::Float4, "a_Color" }
		};
		vertexBuffer->SetLayout(layout);
		mVertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		std::shared_ptr<Quark::IndexBuffer> indexBuffer;
		indexBuffer.reset(Quark::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		mVertexArray->SetIndexBuffer(indexBuffer);

		mSquareVA.reset(Quark::VertexArray::Create());

		float squareVertices[3 * 4] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
		};

		std::shared_ptr<Quark::VertexBuffer> squareVB;
		squareVB.reset(Quark::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ Quark::ShaderDataType::Float3, "a_Position" }
			});
		mSquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<Quark::IndexBuffer> squareIB;
		squareIB.reset(Quark::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		mSquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;
			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;
			
			out vec3 v_Position;
			out vec4 v_Color;
			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			in vec4 v_Color;
			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		mShader.reset(new Quark::Shader(vertexSrc, fragmentSrc));

		std::string blueShaderVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string blueShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			void main()
			{
				color = vec4(0.2, 0.3, 0.8, 1.0);
			}
		)";

		mBlueShader.reset(new Quark::Shader(blueShaderVertexSrc, blueShaderFragmentSrc));
	}

	void OnUpdate(Quark::Timestep ts) override
	{
		if (Quark::Input::IsKeyPressed(QK_KEY_LEFT))
			mCameraPosition.x -= mCameraMoveSpeed * ts;
		else if (Quark::Input::IsKeyPressed(QK_KEY_RIGHT))
			mCameraPosition.x += mCameraMoveSpeed * ts;

		if (Quark::Input::IsKeyPressed(QK_KEY_UP))
			mCameraPosition.y += mCameraMoveSpeed * ts;
		else if (Quark::Input::IsKeyPressed(QK_KEY_DOWN))
			mCameraPosition.y -= mCameraMoveSpeed * ts;

		if (Quark::Input::IsKeyPressed(QK_KEY_A))
			mCameraRotation += mCameraRotationSpeed * ts;
		if (Quark::Input::IsKeyPressed(QK_KEY_D))
			mCameraRotation -= mCameraRotationSpeed * ts;

		Quark::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Quark::RenderCommand::Clear();

		mCamera.SetPosition(mCameraPosition);
		mCamera.SetRotation(mCameraRotation);

		Quark::Renderer::BeginScene(mCamera);

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				Quark::Renderer::Submit(mBlueShader, mSquareVA, transform);
			}
		}
		Quark::Renderer::Submit(mShader, mVertexArray);

		Quark::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{

	}

	void OnEvent(Quark::Event& event) override
	{

	}
	private:
		std::shared_ptr<Quark::Shader> mShader;
		std::shared_ptr<Quark::VertexArray> mVertexArray;

		std::shared_ptr<Quark::Shader> mBlueShader;
		std::shared_ptr<Quark::VertexArray> mSquareVA;

		Quark::OrthographicCamera mCamera;
		glm::vec3 mCameraPosition;
		float mCameraMoveSpeed = 5.0f;

		float mCameraRotation = 0.0f;
		float mCameraRotationSpeed = 180.0f;
};

class Sandbox : public Quark::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}
	virtual ~Sandbox() {
	
	}
};

Quark::Application* Quark::CreateApplication() {
	return new Sandbox();
}