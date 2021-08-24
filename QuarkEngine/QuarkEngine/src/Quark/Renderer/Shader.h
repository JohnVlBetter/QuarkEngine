#pragma once

#include <string>
#include <unordered_map>

namespace Quark {

	class Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual const std::string& GetName() const = 0;

		static SPtr<Shader> Create(const std::string& filepath);
		static SPtr<Shader> Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
	};

	class ShaderLibrary
	{
	public:
		void Add(const std::string& name, const SPtr<Shader>& shader);
		void Add(const SPtr<Shader>& shader);
		SPtr<Shader> Load(const std::string& filepath);
		SPtr<Shader> Load(const std::string& name, const std::string& filepath);

		SPtr<Shader> Get(const std::string& name);

		bool Exists(const std::string& name) const;
	private:
		std::unordered_map<std::string, SPtr<Shader>> mShaders;
	};

}