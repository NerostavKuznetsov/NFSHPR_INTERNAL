// ➡️ ImGui
#include "../../../External/ImGui/imgui_impl_dx11.h"
#include "../../../External/ImGui/imgui_impl_win32.h"
#include "../../../External/ImGui/imgui_internal.h"
#include "../../../External/ImGui/imgui_settings.h"
#include "../../../External/ImGui/imgui.h"

// ➡️ Kiero Hook
#include "../../../External/kiero/kiero.h"

// ➡️ Tabs
#include "../Menu/Tabs/Tab_Config.h"

// ➡️ Config
#include "../Config/Config.h"

// ➡️ DirectX 10 SDK (June 2010)
#include <d3d11.h>

// ➡️ Menu
#include "Menu.h"

// ➡️ Fontes do menu 
#include "Font.h"

IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

ID3D11ShaderResourceView* bg = nullptr;
ImFont* Inter_S = nullptr;
ImFont* Inter_S_1 = nullptr;
ImFont* Inter_S_2 = nullptr;
ImFont* Inter_S_3 = nullptr;
ImFont* Inter_B = nullptr;
ImFont* Icon = nullptr;
ImFont* Icon_Arrow = nullptr;

static int active_tab = 0;
float tab_alpha = 0.f;
float anim_text = 0.f;
int pending_page = 0;
int togle = 0;

static HWND                        window = nullptr;
static WNDPROC                     oWndProc = nullptr;
static ID3D11Device* pDevice = nullptr;
static ID3D11DeviceContext* pContext = nullptr;
static ID3D11RenderTargetView* mainRenderTargetView = nullptr;

static void CreateRenderTarget(IDXGISwapChain* pSwapChain)
{
	ID3D11Texture2D* pBackBuffer = nullptr;
	if (SUCCEEDED(pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBackBuffer)))
	{
		HRESULT hr = pDevice->CreateRenderTargetView(pBackBuffer, nullptr, &mainRenderTargetView);
		pBackBuffer->Release();
	}
}

static void CleanupRenderTarget()
{
	if (mainRenderTargetView)
	{
		mainRenderTargetView->Release();
		mainRenderTargetView = nullptr;
	}
}

LRESULT static __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return TRUE; 

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

static void CustomStyleColor()
{
	ImGuiStyle& s = ImGui::GetStyle();
	ImGuiContext& g = *GImGui;

	s.Colors[ImGuiCol_Border] = ImColor(0, 0, 0, 0); // Sem bordas
	s.Colors[ImGuiCol_PopupBg] = ImColor(7, 8, 18, 127); // Fundo dos popups (menus drop-down)

	s.ChildRounding = 12.f; // Arredondamento das janelas filhas
	s.WindowRounding = 12.f; // Arredondamento das janelas
	s.WindowPadding = ImVec2(0, 0); // Espaçamento interno da janela

	s.Colors[ImGuiCol_ChildBg] = ImColor(0, 0, 0, 255);
	s.Colors[ImGuiCol_WindowBg] = ImColor(10, 10, 10, 255); // Fundo do menu quase preto CINZA Q EU SEMPRE  cinza escuro
}

//==================================================================================
//= Função para renderizar as Tabs =================================================
//==================================================================================																
static void RenderTabs()
{
	anim_text = ImLerp(anim_text, pending_page == active_tab ? 20.f : 0.f, 14.f * ImGui::GetIO().DeltaTime);

	const auto& p = ImGui::GetWindowPos();
	const char* TabNames[] =
	{
		"[Gameplay]",
		"[Weathers]",
		"[Extra Options]",
		"[?]",
		"[?]"
	};

	ImGui::GetWindowDrawList()->AddText(Inter_S_2, 23.f, ImVec2(p.x + 246 + anim_text, p.y + 18),
	ImGui::GetColorU32(c::text_active), TabNames[active_tab]);
	switch (active_tab)
	{
	case 0: Tabs::Tab_0(); break;
	case 1: Tabs::Tab_1(); break;
	case 2: Tabs::Tab_2(); break;
	}
}

void Menu::PlayToggleBeep(bool enabled)
{
	if (enabled)
	{
		std::thread([]() { Beep(666, 100); }).detach(); 
	}
	else
	{
		std::thread([]() { Beep(333, 100); }).detach(); 
	}
}

//==================================================================================
//= Menu ===========================================================================
//==================================================================================
namespace Menu
{
	bool Init(IDXGISwapChain* pSwapChain)
	{

		if (!pSwapChain) return false;

		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)) && pDevice)
		{
			pDevice->GetImmediateContext(&pContext);

			DXGI_SWAP_CHAIN_DESC sd{};
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;

			CreateRenderTarget(pSwapChain);

			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			IMGUI_CHECKVERSION(); // MINHA ImGui COMEÇA AQUI ->>>>>>>> ABAIXO
			ImGui::CreateContext();

			CustomStyleColor();

			ImGuiIO& io = ImGui::GetIO();
			io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

			ImGui_ImplWin32_Init(window);
			ImGui_ImplDX11_Init(pDevice, pContext);

			ImFontConfig cfg; // Config para NÃO deixar o ImGui free-ar seus buffers embutidos
			cfg.FontDataOwnedByAtlas = false; // Essencial p/ AddFontFromMemoryTTF com dados estáticos
			const ImWchar* ranges = nullptr; // Se quiser ranges específicos, mantenha abaixo, senão pode usar nullptr..
			//const ImWchar* ranges = io.Fonts->GetGlyphRangesCyrillic();
			Inter_S = io.Fonts->AddFontFromMemoryTTF((void*)Inter_SemmiBold, sizeof Inter_SemmiBold, 17.f, &cfg, ranges);   // Fonte dos textos normais
			Inter_S_1 = io.Fonts->AddFontFromMemoryTTF((void*)Inter_SemmiBold, sizeof Inter_SemmiBold, 18.f, &cfg, ranges); // Fonte dos títulos das tabs
			Inter_S_2 = io.Fonts->AddFontFromMemoryTTF((void*)Inter_SemmiBold, sizeof Inter_SemmiBold, 23.f, &cfg, ranges); // Fonte dos botões
			Inter_S_3 = io.Fonts->AddFontFromMemoryTTF((void*)Inter_SemmiBold, sizeof Inter_SemmiBold, 15.f, &cfg, ranges); // Fonte do watermark
			Inter_B = io.Fonts->AddFontFromMemoryTTF((void*)Inter_Bold, sizeof Inter_Bold, 34.f, &cfg, ranges);             // Fonte da logo do cheat
			Icon = io.Fonts->AddFontFromMemoryTTF((void*)Icon_Pack, sizeof Icon_Pack, 26.f, &cfg, ranges);                  // Icones para as tabs
			Icon_Arrow = io.Fonts->AddFontFromMemoryTTF((void*)Arrow, sizeof Arrow, 7.f, &cfg, ranges);                     // Icone de seta pequena
			return true;
		}
		return false;
	}

	static void OnResize(IDXGISwapChain* pSwapChain)
	{
		if (!pSwapChain) return;
		ImGui_ImplDX11_InvalidateDeviceObjects();
		CleanupRenderTarget();
		CreateRenderTarget(pSwapChain);
		ImGui_ImplDX11_CreateDeviceObjects();
	}

	void StartRender()
	{
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
	}

	void Render()
	{
		if (ImGui::IsKeyPressed(ImGuiKey_Tab, false))
		{
			Config::MenuImGui = !Config::MenuImGui;
		}

		//==================================================================================
		//= Watermark ======================================================================
		//==================================================================================
		ImGui::SetNextWindowSize(ImVec2(180, 50)); // Largura/Altura da janela do wartermark
		ImGui::SetNextWindowPos({ 10, 10 }); // Posição do watermark na tela
		ImGui::PushStyleColor(ImGuiCol_WindowBg, (ImVec4)ImColor(0, 0, 0, 255)); // Cor do fundo da janela do watermark
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 12.f);
		ImGui::Begin("##watermark", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);
		{
			auto draw = ImGui::GetForegroundDrawList();
			const auto& p = ImGui::GetWindowPos(); // Pega a posição da janela
			const ImVec2& region = ImGui::GetContentRegionMax(); // Pega o tamanho da janela

			// FPS Calculator
			char fps_text[16];
			snprintf(fps_text, sizeof(fps_text), "%.0f", ImGui::GetIO().Framerate);
			ImGui::GetWindowDrawList()->AddText(Inter_S, 17.f, ImVec2(p.x + 20, p.y + 16), ImGui::GetColorU32(c::text_active), fps_text);
			ImGui::GetWindowDrawList()->AddText(Inter_S_3, 15.f, ImVec2(p.x + 55, p.y + 17), ImGui::GetColorU32(c::text_in_active), "FPS");

			// MS Calculator
			float ms = 1000.0f / ImGui::GetIO().Framerate;
			char ms_text[16];
			snprintf(ms_text, sizeof(ms_text), "%.2f", ms);
			ImGui::GetWindowDrawList()->AddText(Inter_S, 17.f, ImVec2(p.x + 100, p.y + 16), ImGui::GetColorU32(c::text_active), ms_text);
			ImGui::GetWindowDrawList()->AddText(Inter_S_3, 15.f, ImVec2(p.x + 140, p.y + 17), ImGui::GetColorU32(c::text_in_active), "MS");

		}
		ImGui::End();
		ImGui::PopStyleVar();

		if (!Config::MenuImGui) return;

		//==================================================================================
		//= Cursor Customizado =============================================================
		//==================================================================================
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDrawCursor = false;
		ImDrawList* draw = ImGui::GetForegroundDrawList();
		ImVec2 pos = io.MousePos;

		float radius = 6.f; // tamanho reduzido da bolinha
		float border = 2.0f; // espessura do contorno roxo

		ImU32 colInner = IM_COL32(0, 0, 0, 255); // Cor interna preta
		ImU32 colBorder = IM_COL32(170, 34, 255, 255); // Cor do contorno roxo

		draw->AddCircleFilled(pos, radius, colInner, 32); // Desenha bolinha interna preta
		draw->AddCircle(pos, radius, colBorder, 32, border); // Desenha contorno roxo

		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImColor(10, 10, 10, 255).Value);
		ImGui::SetNextWindowSize(ImVec2(1055, 450)); // Largura/Altura da janela do MENU PRINCIPAL !!!
		ImGui::Begin("General", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBringToFrontOnFocus);
		{
			auto draw = ImGui::GetWindowDrawList();
			const auto& p = ImGui::GetWindowPos();
			const ImVec2& region = ImGui::GetContentRegionMax();

			tab_alpha = ImLerp(tab_alpha, (pending_page == active_tab) ? 1.f : 0.f, 18.f * ImGui::GetIO().DeltaTime);
			if (tab_alpha < 0.01f) 
			active_tab = pending_page;

			ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(p.x, p.y), ImVec2(p.x + 250, p.y + region.y), ImGui::GetColorU32(c::child_rect), 12.f, ImDrawFlags_RoundCornersLeft); // 
			ImGui::GetWindowDrawList()->AddText(Inter_B, 34.f, ImVec2(p.x + 10, p.y + 32), ImGui::GetColorU32(c::main_color), "NFS Hot Pursuit Remastered");
			ImGui::GetWindowDrawList()->AddText(Inter_B, 34.f, ImVec2(p.x + 115, p.y + 32), ImGui::GetColorU32(c::text_active), "");

			ImGuiStyle* style = &ImGui::GetStyle();
			ImGui::PushStyleVar(ImGuiStyleVar_Alpha, tab_alpha * style->Alpha);
			{
				RenderTabs();
			}
			ImGui::PopStyleVar();

			ImGui::SetCursorPos(ImVec2(8, 110));
			ImGui::BeginGroup();
			{
				ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 8));
				if (ImGui::Tab("Gameplay",       "V", 0 == pending_page, ImVec2(234, 50))) pending_page = 0;
				if (ImGui::Tab("Weathers",       "V", 1 == pending_page, ImVec2(234, 50))) pending_page = 1;
				if (ImGui::Tab("Extra Options",  "V", 2 == pending_page, ImVec2(234, 50))) pending_page = 2;
				if (ImGui::Tab("Extra Weathers", "V", 3 == pending_page, ImVec2(234, 50))) pending_page = 3;
				ImGui::PopStyleVar();
			}
			ImGui::EndGroup();
		}
		ImGui::End();
		ImGui::PopStyleColor();
	}

	void EndRender()
	{
		ImGui::Render();
		if (pContext && mainRenderTargetView)
		{
			pContext->OMSetRenderTargets(1, &mainRenderTargetView, nullptr);
		}
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	}

	void Unload()
	{
		SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)oWndProc);
		oWndProc = nullptr;

		ImGui_ImplDX11_Shutdown();
		ImGui_ImplWin32_Shutdown();
		ImGui::DestroyContext();
	}
}


