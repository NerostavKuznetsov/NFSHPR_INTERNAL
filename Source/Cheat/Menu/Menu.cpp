// ➡️ ImGui
#include "../../../External/ImGui/imgui.h"
#include "../../../External/ImGui/imgui_impl_dx11.h"
#include "../../../External/ImGui/imgui_impl_win32.h"
#include "../../../External/ImGui/imgui_internal.h"
#include "../../../External/ImGui/imgui_settings.h"

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

static ID3D11Device*               g_pd3dDevice = NULL;
static ID3D11DeviceContext*        g_pd3dDeviceContext = NULL;
static IDXGISwapChain*             g_pSwapChain = NULL;
static ID3D11RenderTargetView*     g_mainRenderTargetView = NULL;

static HWND                        window = nullptr;
static WNDPROC                     oWndProc = nullptr;
static ID3D11Device*               pDevice = nullptr;
static ID3D11DeviceContext*        pContext = nullptr;
static ID3D11RenderTargetView*     mainRenderTargetView = nullptr;

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

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return TRUE; // LRESULT ok

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

ID3D11ShaderResourceView* bg = nullptr;
ImFont* Inter_S = nullptr;
ImFont* Inter_S_1 = nullptr;
ImFont* Inter_S_2 = nullptr;
ImFont* Inter_S_3 = nullptr;
ImFont* Inter_B = nullptr;
ImFont* Icon = nullptr;
ImFont* Icon_Arrow = nullptr;

int sub_page = 0;
int page = 0;
int togle = 0;


void CustomStyleColor()
{
	ImGuiStyle& s = ImGui::GetStyle();
	ImGuiContext& g = *GImGui;

	s.Colors[ImGuiCol_Border] = ImColor(0, 0, 0, 0);
	s.Colors[ImGuiCol_PopupBg] = ImColor(7, 8, 18, 127);

	s.ChildRounding = 12.f;
	s.WindowRounding = 12.f;
	s.WindowPadding = ImVec2(0, 0);

	s.Colors[ImGuiCol_ChildBg] = ImColor(0, 0, 0, 255);
	s.Colors[ImGuiCol_WindowBg] = ImColor(10, 10, 10, 255); // Fundo do menu quase preto CINZA Q EU SEMPRE
}

// ------------------------------------------------------------------
// Função auxiliar para renderizar as tabs	
// ------------------------------------------------------------------
float tab_alpha = 0.f; /* */ static float tab_add; /* */ static int active_tab = 0;
float anim_text = 0.f; /* */

void RenderTabs()  
{
	anim_text = ImLerp(anim_text, page == active_tab ? 20.f : 0.f, 14.f * ImGui::GetIO().DeltaTime);

	switch (active_tab)
	{
	case 0: Tabs::Gameplay(); break;
	case 1: Tabs::Weathers(); break;
	//case 2: Tabs::Visuals(); break;



	}
}















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

			// MINHA ImGui COMEÇA AQUI ->>>>>>>>
			IMGUI_CHECKVERSION();
			ImGui::CreateContext();
			ImGui::StyleColorsDark();

			ImGuiIO& io = ImGui::GetIO();
			io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

			ImGui_ImplWin32_Init(window);
			ImGui_ImplDX11_Init(pDevice, pContext);

			// >>> Config para NÃO deixar o ImGui free-ar seus buffers embutidos
			ImFontConfig cfg;
			cfg.FontDataOwnedByAtlas = false; // >>> essencial p/ AddFontFromMemoryTTF com dados estáticos

			// >>> Se quiser ranges específicos, mantenha; senão pode usar nullptr
			const ImWchar* ranges = io.Fonts->GetGlyphRangesCyrillic();

			Inter_S = io.Fonts->AddFontFromMemoryTTF((void*)Inter_SemmiBold, sizeof Inter_SemmiBold, 17.f, &cfg, ranges); // Fonte dos textos normais

			Inter_S_1 = io.Fonts->AddFontFromMemoryTTF((void*)Inter_SemmiBold, sizeof Inter_SemmiBold, 18.f, &cfg, ranges); // Fonte dos títulos das tabs



			Inter_S_2 = io.Fonts->AddFontFromMemoryTTF((void*)Inter_SemmiBold, sizeof Inter_SemmiBold, 23.f, &cfg, ranges); // Fonte dos botões .??????????????????????????????????????




			Inter_S_3 = io.Fonts->AddFontFromMemoryTTF((void*)Inter_SemmiBold, sizeof Inter_SemmiBold, 15.f, &cfg, ranges); // Fonte do watermark

			Inter_B = io.Fonts->AddFontFromMemoryTTF((void*)Inter_Bold, sizeof Inter_Bold, 34.f, &cfg, ranges); // Fonte da logo do cheat

			Icon = io.Fonts->AddFontFromMemoryTTF((void*)Icon_Pack, sizeof Icon_Pack, 26.f, &cfg, ranges); // Icones para as tabs

			Icon_Arrow = io.Fonts->AddFontFromMemoryTTF((void*)Arrow, sizeof Arrow, 7.f, &cfg, ranges);

			//Icon_Arrow = io.Fonts->AddFontFromMemoryTTF(&Arrow, sizeof Arrow, 6.f, NULL, io.Fonts->GetGlyphRangesCyrillic()); // errror crash na hora de unloading
			// NÃO use io.Fonts->SetFontAtlasOwnedByContext(false) aqui, a menos que você próprio tenha criado o ImFontAtlas fora do ImGui e queira mantê-lo vivo após DestroyContext().
			return true;
		}
		return false;
	}

	// Chame isto quando houver ResizeBuffers no seu hook
	void OnResize(IDXGISwapChain* pSwapChain)
	{
		if (!pSwapChain) return;
		ImGui_ImplDX11_InvalidateDeviceObjects(); // garante reconstrução se necessário
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

		// Toggle do menu apenas quando a tecla é pressionada (não segurada)
		// ✔ toggle anti-repetição
		// ✔ evita spam quando segura INSERT
		static bool insertPressedLastFrame = false;
		//bool insertPressedNow = (GetAsyncKeyState(VK_INSERT) & 0x8000) != 0;
		bool insertPressedNow = (GetAsyncKeyState(VK_TAB) & 0x8000) != 0;
		if (insertPressedNow && !insertPressedLastFrame)
			Config::MenuImGui = !Config::MenuImGui;
		insertPressedLastFrame = insertPressedNow;

		// Mostra ou esconde o cursor conforme o menu
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDrawCursor = Config::MenuImGui;

		if (!Config::MenuImGui)
			return;

		ImGuiContext& g = *GImGui;
		ImGuiStyle* style = &ImGui::GetStyle();




		// -----------------------------------------------------
		// Janela do Watermark 
		// -----------------------------------------------------
		ImGui::SetNextWindowSize(ImVec2(180, 50)); // Largura/Altura da janela do wartermark
		ImGui::SetNextWindowPos({ 10, 10 }); // Posição do watermark na tela
		ImGui::PushStyleColor(ImGuiCol_WindowBg, (ImVec4)ImColor(0, 0, 0, 255)); 
		ImGui::Begin("##watermark", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);
		{





			auto draw = ImGui::GetForegroundDrawList();
	
			const auto& p = ImGui::GetWindowPos(); // Pega a posição da janela
	
			const ImVec2& region = ImGui::GetContentRegionMax(); // Pega o tamanho da janela





			SYSTEMTIME st; // Estrutura para armazenar o tempo local
			GetLocalTime(&st); // Obtém o tempo local

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
			ImGui::GetWindowDrawList()->AddText(Inter_S_3, 15.f, ImVec2(p.x + 135, p.y + 17), ImGui::GetColorU32(c::text_in_active), "MS"); // x vai para direita e y esquerda

		}
		ImGui::End();
		// -----------------------------------------------------
		// Fim do Watermark 
		// -----------------------------------------------------








		CustomStyleColor();
		ImGui::SetNextWindowSize(ImVec2(1055, 490)); 
		ImGui::Begin("General", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBringToFrontOnFocus);
		{
			auto draw = ImGui::GetWindowDrawList();

			const auto& p = ImGui::GetWindowPos();
			const ImVec2& region = ImGui::GetContentRegionMax();

			tab_alpha = ImLerp(tab_alpha, (page == active_tab) ? 1.f : 0.f, 18.f * ImGui::GetIO().DeltaTime);
			if (tab_alpha < 0.01f && tab_add < 0.01f) active_tab = page;

			ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(p.x, p.y), ImVec2(p.x + 250, p.y + region.y), ImGui::GetColorU32(c::child_rect), 12.f, ImDrawFlags_RoundCornersLeft);

			ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(p.x, p.y), ImVec2(p.x + 250, p.y + region.y), ImGui::GetColorU32(c::child_rect), 12.f, ImDrawFlags_RoundCornersLeft);
			ImGui::GetWindowDrawList()->AddText(Inter_B, 34.f, ImVec2(p.x + 10, p.y + 32), ImGui::GetColorU32(c::main_color), "    Nerostav"); // 27 32

			ImGui::GetWindowDrawList()->AddText(Inter_B, 34.f, ImVec2(p.x + 115, p.y + 32), ImGui::GetColorU32(c::text_active), ""); // 125 32

			ImGui::SetCursorPos(ImVec2(8, 110)); // estava 112
			ImGui::BeginGroup();
			{
				ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 8));

				if (ImGui::Tab("Gameplay", "A", 0 == page, ImVec2(234, 50))) page = 0;

				if (ImGui::Tab("Weathers", "L", 1 == page, ImVec2(234, 50))) page = 1;

				if (ImGui::Tab("Bounty", "V", 2 == page, ImVec2(234, 50))) page = 2;

				if (ImGui::Tab("IA", "S", 3 == page, ImVec2(234, 50))) page = 3;

				if (ImGui::Tab("Config", "C", 4 == page, ImVec2(234, 50))) page = 4;

				ImGui::PopStyleVar();
			}
			ImGui::EndGroup();





			ImGui::PushStyleVar(ImGuiStyleVar_Alpha, tab_alpha * style->Alpha);
			{
				anim_text = ImLerp(anim_text, page == active_tab ? 20.f : 0.f, 14.f * ImGui::GetIO().DeltaTime); // Animação do texto das tabs EX: [Gameplay]

				RenderTabs();
			}
			ImGui::PopStyleVar();
		}
		ImGui::End();
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
