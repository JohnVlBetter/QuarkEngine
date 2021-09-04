#pragma once

#include <filesystem>

#include "Quark/Renderer/Texture.h"

namespace Quark {

	class ContentBrowserPanel
	{
	public:
		ContentBrowserPanel();

		void OnImGuiRender();
	private:
		std::filesystem::path mCurrentDirectory;

		SPtr<Texture2D> mDirectoryIcon;
		SPtr<Texture2D> mFileIcon;
	};

}
