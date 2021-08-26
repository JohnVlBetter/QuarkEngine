#include "qkpch.h"
#include "Quark/Renderer/Shader.h"

#include "Quark/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Quark {
	SPtr<Shader> Shader::Create(const std::string& filepath)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    QK_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateSPtr<OpenGLShader>(filepath);
		}

		QK_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	SPtr<Shader> Shader::Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		// Create an empty vertex shader handle
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    QK_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateSPtr<OpenGLShader>(name, vertexSrc, fragmentSrc);
		}

		QK_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	void ShaderLibrary::Add(const std::string& name, const SPtr<Shader>& shader)
	{
		QK_CORE_ASSERT(!Exists(name), "Shader already exists!");
		mShaders[name] = shader;
	}

	void ShaderLibrary::Add(const SPtr<Shader>& shader)
	{
		auto& name = shader->GetName();
		Add(name, shader);
	}

	SPtr<Quark::Shader> ShaderLibrary::Load(const std::string& filepath)
	{
		auto shader = Shader::Create(filepath);
		Add(shader);
		return shader;
	}

	SPtr<Quark::Shader> ShaderLibrary::Load(const std::string& name, const std::string& filepath)
	{
		auto shader = Shader::Create(filepath);
		Add(name, shader);
		return shader;
	}

	SPtr<Quark::Shader> ShaderLibrary::Get(const std::string& name)
	{
		QK_CORE_ASSERT(Exists(name), "Shader not found!");
		return mShaders[name];
	}

	bool ShaderLibrary::Exists(const std::string& name) const
	{
		return mShaders.find(name) != mShaders.end();
	}
}