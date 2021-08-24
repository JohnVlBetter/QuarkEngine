#include "qkpch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace Quark {

	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case Quark::ShaderDataType::Float:    return GL_FLOAT;
		case Quark::ShaderDataType::Float2:   return GL_FLOAT;
		case Quark::ShaderDataType::Float3:   return GL_FLOAT;
		case Quark::ShaderDataType::Float4:   return GL_FLOAT;
		case Quark::ShaderDataType::Mat3:     return GL_FLOAT;
		case Quark::ShaderDataType::Mat4:     return GL_FLOAT;
		case Quark::ShaderDataType::Int:      return GL_INT;
		case Quark::ShaderDataType::Int2:     return GL_INT;
		case Quark::ShaderDataType::Int3:     return GL_INT;
		case Quark::ShaderDataType::Int4:     return GL_INT;
		case Quark::ShaderDataType::Bool:     return GL_BOOL;
		}

		QK_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &mRendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &mRendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(mRendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const SPtr<VertexBuffer>& vertexBuffer)
	{
		QK_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout!");

		glBindVertexArray(mRendererID);
		vertexBuffer->Bind();

		uint32_t index = 0;
		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset);
			index++;
		}

		mVertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const SPtr<IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(mRendererID);
		indexBuffer->Bind();

		mIndexBuffer = indexBuffer;
	}

}