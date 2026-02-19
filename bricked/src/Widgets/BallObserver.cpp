#include "BallObserver.h"
#include "imgui/imgui.h"
#include<string>
#include <format>

#include "../Entities/Ball.h"

void BallObserver::Draw()
{
	ImGui::Begin("Ball Observer");

	std::string ballText = std::format("Ball: {:p}", (void*)ball);
	ImGui::Text(ballText.c_str());

	if (ImGui::Button("Debug Mode")) {
		ball->DebugMode = !ball->DebugMode;
	}
	if (ImGui::Button("Reset")) {
		ball->Reset();
	}

	Vector2 vel = ball->GetVelocity();
	float v[2] = { vel.X, vel.Y };
	ImGui::InputFloat2("Velocity", v);

	std::string debugText = "Debug Mode: {:p}" + std::to_string(ball->DebugMode);
	
	ImGui::InputFloat("Speed: ", &ball->speed);
	ImGui::InputInt("Damage: ", &ball->Damage);

	ImGui::End();
}
