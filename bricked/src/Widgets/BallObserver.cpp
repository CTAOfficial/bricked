#include "BallObserver.h"
#include "imgui/imgui.h"
#include<string>
#include <format>

#include "Entities/Ball.h"

void BallObserver::OnDraw()
{
	std::string ballText = std::format("Ball: {:p}", (void*)ball);
	ImGui::Text(ballText.c_str());

	std::string debugText = "Debug Mode: " + std::to_string(ball->DebugMode);
	if (ImGui::Button(debugText.c_str())) {
		ball->DebugMode = !ball->DebugMode;
	}
	if (ImGui::Button("Reset")) {
		ball->Reset();
	}

	Vector2 vel = ball->GetVelocity();
	float v[2] = { vel.X, vel.Y };
	ImGui::InputFloat2("Velocity", v);
	
	ImGui::InputFloat("Speed: ", &ball->speed);
	ImGui::InputInt("Damage: ", &ball->Damage);
}
