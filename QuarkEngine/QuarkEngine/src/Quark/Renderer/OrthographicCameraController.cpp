#include "qkpch.h"
#include "OrthographicCameraController.h"

#include "Quark/Core/Input.h"
#include "Quark/Core/KeyCodes.h"

namespace Quark {

	OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool rotation)
		: mAspectRatio(aspectRatio), mCamera(-mAspectRatio * mZoomLevel, mAspectRatio * mZoomLevel, -mZoomLevel, mZoomLevel), mRotation(rotation)
	{
	}

	void OrthographicCameraController::OnUpdate(Timestep ts)
	{
		QK_PROFILE_FUNCTION();

		if (Input::IsKeyPressed(Key::A))
			mCameraPosition.x -= mCameraTranslationSpeed * ts;
		else if (Input::IsKeyPressed(Key::D))
			mCameraPosition.x += mCameraTranslationSpeed * ts;

		if (Input::IsKeyPressed(Key::W))
			mCameraPosition.y += mCameraTranslationSpeed * ts;
		else if (Input::IsKeyPressed(Key::S))
			mCameraPosition.y -= mCameraTranslationSpeed * ts;

		if (mRotation)
		{
			if (Input::IsKeyPressed(Key::Q))
				mCameraRotation += mCameraRotationSpeed * ts;
			if (Input::IsKeyPressed(Key::E))
				mCameraRotation -= mCameraRotationSpeed * ts;

			mCamera.SetRotation(mCameraRotation);
		}

		mCamera.SetPosition(mCameraPosition);

		mCameraTranslationSpeed = mZoomLevel;
	}

	void OrthographicCameraController::OnEvent(Event& e)
	{
		QK_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(QK_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
		dispatcher.Dispatch<WindowResizeEvent>(QK_BIND_EVENT_FN(OrthographicCameraController::OnWindowResized));
	}

	void OrthographicCameraController::OnResize(float width, float height)
	{
		mAspectRatio = width / height;
		mCamera.SetProjection(-mAspectRatio * mZoomLevel, mAspectRatio * mZoomLevel, -mZoomLevel, mZoomLevel);
	}

	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e)
	{
		QK_PROFILE_FUNCTION();

		mZoomLevel -= e.GetYOffset() * 0.25f;
		mZoomLevel = std::max(mZoomLevel, 0.05f);
		mCamera.SetProjection(-mAspectRatio * mZoomLevel, mAspectRatio * mZoomLevel, -mZoomLevel, mZoomLevel);
		return false;
	}

	bool OrthographicCameraController::OnWindowResized(WindowResizeEvent& e)
	{
		QK_PROFILE_FUNCTION();

		mAspectRatio = (float)e.GetWidth() / (float)e.GetHeight();
		mCamera.SetProjection(-mAspectRatio * mZoomLevel, mAspectRatio * mZoomLevel, -mZoomLevel, mZoomLevel);
		OnResize((float)e.GetWidth(), (float)e.GetHeight());
		return false;
	}

}