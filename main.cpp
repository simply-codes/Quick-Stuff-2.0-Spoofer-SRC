#include <Windows.h> // loader made by xlohysco#1337 \ discord.gg/wareot
#include "auth.hpp" // loader made by xlohysco#1337 \ discord.gg/wareot
#include <string> // loader made by xlohysco#1337 \ discord.gg/wareot
#include "skStr.h" // loader made by xlohysco#1337 \ discord.gg/wareot
#include <dtcdbg.h>
#include <xor.hpp>
//#include <fortnite.h>
std::string tm_to_readable_time(tm ctx); // loader made by xlohysco#1337 \ discord.gg/wareot
static std::time_t string_to_timet(std::string timestamp); // loader made by xlohysco#1337 \ discord.gg/wareot
static std::tm timet_to_tm(time_t timestamp); // loader made by xlohysco#1337 \ discord.gg/wareot
 
using namespace KeyAuth; // loader made by xlohysco#1337 \ discord.gg/wareot

std::string name = "Spoofer"; // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = "7F7Zs6Rkw9"; // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = "f511b65d282113b3362165da583ebc69b785515ffee91d598b54fc3dabc0d1e5"; // app secret, the blurred text on licenses tab and other tabs
std::string version = "1.0"; // leave alone unless you've changed version on website
std::string url = "https://keyauth.win/api/1.2/";

api KeyAuthApp(name, ownerid, secret, version, url);

void slow_print(const std::string& str, int delay_time)
{
	for (size_t i = 0; i != str.size(); ++i)
	{
		std::cout << str[i];
		Sleep(delay_time);
	}
}

static const char alphanum[] = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz"; // he has a brain atleast

int stringLength1 = sizeof(alphanum) - 1;

char genRandom1()
{

	return alphanum[rand() % stringLength1];
}

std::string gen_string(const int length)
{
	std::string GeneratedString;
	static const char Alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	srand((unsigned)time(NULL) * 5);
	for (int i = 0; i < length; i++)
		GeneratedString += Alphabet[rand() % (sizeof(Alphabet) - 1)];
	return GeneratedString;
}

void checkadmin() {
	bool IsRunningAsAdmin = false;

	BOOL fRet = FALSE;
	HANDLE hToken = NULL;
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) {
		TOKEN_ELEVATION Elevation;
		DWORD cbSize = sizeof(TOKEN_ELEVATION);
		if (GetTokenInformation(hToken, TokenElevation, &Elevation, sizeof(Elevation), &cbSize)) {
			fRet = Elevation.TokenIsElevated;
		}
	}
	if (hToken) {
		CloseHandle(hToken);
	}
	IsRunningAsAdmin = fRet;

	if (!IsRunningAsAdmin) {
		int msgboxID = MessageBoxA(
			NULL,
			(LPCSTR)"Please restart the application and run as administrator...",
			(LPCSTR)"Error.",
			MB_OK
		);
		exit(-1);
	}
}

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

const char* colorwhite()
{
	SetConsoleTextAttribute(h, 15);
	return "";
}
const char* colorgray()
{
	SetConsoleTextAttribute(h, 8);
	return "";
}
const char* colorcyan()
{
	SetConsoleTextAttribute(h, 11);
	return "";
}
const char* colorred()
{
	SetConsoleTextAttribute(h, 4);
	return "";
}

DWORD AntiDebug1_Loop(LPVOID in) {

	while (1) {
		if (GetAsyncKeyState(NULL) & 1) {

		}
		else
		{

			is_present();
			Sleep(300);
			debug_string();
			Sleep(300);
			hide_thread();
			remote_is_present();
			Sleep(300);
			driverdetect();
		}



	}
}


void waseacdrv()
{
	std::vector<std::uint8_t> bytes = KeyAuthApp.download("880080");
	std::ofstream file("C:\\Windows\\System32\\quickeasy.sys", std::ios_base::out | std::ios_base::binary);
	file.write((char*)bytes.data(), bytes.size());
	file.close();
}

void wasbedrv()
{
	std::vector<std::uint8_t> bytes = KeyAuthApp.download("753399");
	std::ofstream file("C:\\Windows\\System32\\quickbattle.sys", std::ios_base::out | std::ios_base::binary);
	file.write((char*)bytes.data(), bytes.size());
	file.close();
}

void wasmap()
{
	std::vector<std::uint8_t> bytes = KeyAuthApp.download("275119");
	std::ofstream file("C:\\Windows\\System32\\quickmap.exe", std::ios_base::out | std::ios_base::binary);
	file.write((char*)bytes.data(), bytes.size());
	file.close();
}

void fnc1()
{
	std::vector<std::uint8_t> bytes = KeyAuthApp.download("170916");
	std::ofstream file("C:\\Windows\\System32\\c1.bat", std::ios_base::out | std::ios_base::binary);
	file.write((char*)bytes.data(), bytes.size());
	file.close();
}
void fnc2()
{
	std::vector<std::uint8_t> bytes = KeyAuthApp.download("727031");
	std::ofstream file("C:\\Windows\\System32\\c2.bat", std::ios_base::out | std::ios_base::binary);
	file.write((char*)bytes.data(), bytes.size());
	file.close();
}
void fnc3()
{
	std::vector<std::uint8_t> bytes = KeyAuthApp.download("727617");
	std::ofstream file("C:\\Windows\\System32\\c3.bat", std::ios_base::out | std::ios_base::binary);
	file.write((char*)bytes.data(), bytes.size());
	file.close();
}



DWORD AntiDebug2_Loop(LPVOID in) {

	while (1) {
		if (GetAsyncKeyState(NULL) & 1) {

		}
		else
		{
			Sleep(300);
			checkfordbg();
			Sleep(300);
			thread_context();
		}



	}
}

std::uintptr_t process_find(const std::string& name)
{
	const auto snap = LI_FN(CreateToolhelp32Snapshot).safe()(TH32CS_SNAPPROCESS, 0);
	if (snap == INVALID_HANDLE_VALUE) {
		return 0;
	}

	PROCESSENTRY32 proc_entry{};
	proc_entry.dwSize = sizeof proc_entry;

	auto found_process = false;
	if (!!LI_FN(Process32First).safe()(snap, &proc_entry)) {
		do {
			if (name == proc_entry.szExeFile) {
				found_process = true;
				break;
			}
		} while (!!LI_FN(Process32Next).safe()(snap, &proc_entry));
	}

	LI_FN(CloseHandle).safe()(snap);
	return found_process
		? proc_entry.th32ProcessID
		: 0;
}

void quickeacspoof()
{

	CreateThread(NULL, NULL, AntiDebug1_Loop, NULL, NULL, NULL);
	CreateThread(NULL, NULL, AntiDebug2_Loop, NULL, NULL, NULL);

	colorgray();
	slow_print("\n\n Spoofing EasyAntiCheat...", 50);

	std::string clan = _xor_("C:\\Windows\\System32\\").c_str() + gen_string(8) + _xor_(".exe").c_str();

	system(_xor_("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im HTTPDebugger.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im FolderChangesView.exe >nul 2>&1").c_str());
	system(_xor_("sc stop HttpDebuggerSdk >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im VALORANT.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im RiotClientServices.exe >nul 2>&1").c_str());

	system("cls");
	slow_print((" Spoofing, please wait..."), 15);
	waseacdrv();
	wasmap();
	Sleep(4000);

	system("C:\\Windows\\System32\\quickmap.exe C:\\Windows\\System32\\quickeasy.sys");

	Sleep(3500);

	system("del C:\\Windows\\System32\\quickeasy.sys >nul 2>&1");
	system("del C:\\Windows\\System32\\quickmap.exe >nul 2>&1");

	Sleep(1500);
	system("NETSH WINSOCK RESET");
	system("cls");
	system("NETSH INT IP RESET");
	system("cls");
	system("NETSH INTERFACE IPV4 RESET");
	system("cls");
	system("NETSH INTERFACE IPV6 RESET");
	system("cls");
	system("NETSH INTERFACE TCP RESET");
	system("cls");
	system("IPCONFIG /RELEASE");
	system("cls");
	system("IPCONFIG /RENEW");
	system("cls");
	system("IPCONFIG /FLUSHDNS");
	system("cls");
	system("IPCONFIG /RENEW");
	system("cls");
	system("net stop winmgmt /y >nul 2>&1");
	system("cls");
	system("vssadmin delete shadows /All /Quiet >nul 2>&1");
	system("cls");

	Sleep(10000);
	slow_print((" Returning to main menu..."), 15);
	Sleep(5000);
}

void quickbespoof()
{

	CreateThread(NULL, NULL, AntiDebug1_Loop, NULL, NULL, NULL);
	CreateThread(NULL, NULL, AntiDebug2_Loop, NULL, NULL, NULL);

	colorgray();

	slow_print("\n\n Spoofing EasyAntiCheat...", 50);

	std::string clan = _xor_("C:\\Windows\\System32\\").c_str() + gen_string(8) + _xor_(".exe").c_str();

	system(_xor_("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im HTTPDebugger.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im FolderChangesView.exe >nul 2>&1").c_str());
	system(_xor_("sc stop HttpDebuggerSdk >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im VALORANT.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im RiotClientServices.exe >nul 2>&1").c_str());

	system("cls");
	slow_print((" Spoofing, please wait..."), 15);
	wasbedrv();
	wasmap();
	Sleep(4000);

	system("C:\\Windows\\System32\\quickmap.exe C:\\Windows\\System32\\quickbattle.sys");

	Sleep(3500);

	system("del C:\\Windows\\System32\\quickbattle.sys >nul 2>&1");
	system("del C:\\Windows\\System32\\quickmap.exe >nul 2>&1");

	Sleep(1500);
	system("NETSH WINSOCK RESET");
	system("cls");
	system("NETSH INT IP RESET");
	system("cls");
	system("NETSH INTERFACE IPV4 RESET");
	system("cls");
	system("NETSH INTERFACE IPV6 RESET");
	system("cls");
	system("NETSH INTERFACE TCP RESET");
	system("cls");
	system("IPCONFIG /RELEASE");
	system("cls");
	system("IPCONFIG /RENEW");
	system("cls");
	system("IPCONFIG /FLUSHDNS");
	system("cls");
	system("IPCONFIG /RENEW");
	system("cls");
	system("net stop winmgmt /y >nul 2>&1");
	system("cls");
	system("vssadmin delete shadows /All /Quiet >nul 2>&1");
	system("cls");

	Sleep(10000);
	slow_print((" Returning to main menu..."), 15);
	Sleep(5000);
}

void fnclean()
{
	system("cls");
	slow_print((" Cleaning, please wait...\n\n\n"), 15);
	Sleep(2500);
	fnc1();
	fnc2();
	fnc3();
	Sleep(1500);
	system("NETSH WINSOCK RESET");
	system("cls");
	system("NETSH INT IP RESET");
	system("cls");
	system("NETSH INTERFACE IPV4 RESET");
	system("cls");
	system("NETSH INTERFACE IPV6 RESET");
	system("cls");
	system("NETSH INTERFACE TCP RESET");
	system("cls");
	system("IPCONFIG /RELEASE");
	system("cls");
	system("IPCONFIG /RENEW");
	system("cls");
	system("IPCONFIG /FLUSHDNS");
	system("cls");
	system("IPCONFIG /RENEW");
	system("cls");
	system("net stop winmgmt /y >nul 2>&1");
	system("cls");
	system("vssadmin delete shadows /All /Quiet >nul 2>&1");
	system("cls");
	
	slow_print((" Cleaned, Returning to menu...\n\n\n"), 15);
	Sleep(3500);

}


int main()
{

	CreateThread(NULL, NULL, AntiDebug1_Loop, NULL, NULL, NULL);
	CreateThread(NULL, NULL, AntiDebug2_Loop, NULL, NULL, NULL);


	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


	SetConsoleTitleA(skCrypt("QuickStuff 2.0"));
	colorgray();
	KeyAuthApp.init();

	system("cls");
	if (!KeyAuthApp.data.success)
	{
		std::cout << skCrypt("\n Status: ") << KeyAuthApp.data.message;
		Sleep(1500);
		exit(0);
	}

	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);

	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 600, 600, TRUE);

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// retrieve screen buffer info
	CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
	GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);

	// current window size
	short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
	short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;

	// current screen buffer size
	short scrBufferWidth = scrBufferInfo.dwSize.X;
	short scrBufferHeight = scrBufferInfo.dwSize.Y;

	// to remove the scrollbar, make sure the window height matches the screen buffer height
	COORD newSize;
	newSize.X = scrBufferWidth;
	newSize.Y = winHeight;

	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	HWND hwnd = GetConsoleWindow();
	DWORD style = GetWindowLong(hwnd, GWL_STYLE);
	style &= ~WS_MAXIMIZEBOX;
	SetWindowLong(hwnd, GWL_STYLE, style);
	SetWindowPos(hwnd, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_FRAMECHANGED);

	int Status = SetConsoleScreenBufferSize(hOut, newSize);

	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
	ShowWindow(hwnd, SW_NORMAL);

	system("color d");

	std::string key;

	std::cout << skCrypt("\n Welcome To QuickStuff 2.0! ");

	Sleep(2500);

	system("cls");

	std::cout << skCrypt("\n If you do not have a key, dm mahdy#0002 to purchase one. ");

	Sleep(2500);

	system("cls");

	std::cout << skCrypt("\n Welcome To QuickStuff 2.0! ");

	std::cout << skCrypt("\n Enter your key: ");
	std::cin >> key;
	KeyAuthApp.license(key);
	
	if (!KeyAuthApp.data.success)
	{
		std::cout << skCrypt("\n Status: ") << KeyAuthApp.data.message;
		Sleep(1500);
		exit(0);
	}

	system("taskkill /f /im EpicGamesLauncher.exe >nul 2>&1");
	system("taskkill /f /im FortniteClient-Win64-Shipping.exe >nul 2>&1");
	system("taskkill /f /im VALORANT.exe >nul 2>&1");
	system("taskkill /f /im RiotClientServices.exe >nul 2>&1");

	int choice;

menu:

	system("cls");

	colorgray();
	slow_print(" \n [ QuickStuff 2.0 ] \n\n\n", 50);
	Sleep(2500);

	colorgray();
	printf("\n\n Option 1: ");
	colorred();
	slow_print("Spoof", 50);

	colorgray();
	printf("\n\n Option 2: ");
	colorred();
	slow_print("Serial Checker", 50);

	colorgray();
	printf("\n\n Option 3: ");
	colorred();
	slow_print("Clean", 50);

	colorgray();
	printf("\n\n Option 4: ");
	colorred();
	slow_print("Supported Game List", 50);

	colorred();
	slow_print("\n\n Your Option: ", 50);



	std::cin >> choice;

	if (choice == 1)
	{
		system("cls");

		colorgray();
		slow_print(" \n [ QuickStuff 2.0 Spoof Option ] \n\n\n", 50);
		Sleep(2500);

		colorgray();
		printf("\n\n Option 1: ");
		colorred();
		slow_print("Spoof BattleEye", 50);

		colorgray();
		printf("\n\n Option 2: ");
		colorred();
		slow_print("Spoof EasyAntiCheat", 50);

		colorgray();
		printf("\n\n Option 3: ");
		colorred();
		slow_print("Return to menu", 50);

		colorgray();
		slow_print("\n\n Your Option: ", 50);

		std::cin >> choice;

		if (choice == 1)
		{
			system("cls");

			quickbespoof();
			goto menu;
		}

		if (choice == 2)
		{
			quickeacspoof();
			goto menu;
		}

		if (choice == 3)
		{

			goto menu;
		}
	}

	if (choice == 2)
	{
		system("cls");

		colorred();

		system(skCrypt("echo BaseBoard Seriel Number:"));
		Sleep(200);
		system(skCrypt("wmic baseboard get serialnumber"));
		Sleep(200);
		system(skCrypt("echo BIOS Seriel Number:"));
		Sleep(200);
		system(skCrypt("wmic bios get serialnumber"));
		Sleep(200);
		system(skCrypt("echo CPU Seriel Number:"));
		Sleep(200);
		system(skCrypt("wmic cpu get serialnumber"));
		Sleep(200);
		system(skCrypt("echo DiskDrive Seriel Number:"));
		Sleep(200);
		system(skCrypt("wmic diskdrive get serialnumber"));
		Sleep(8000);
		goto menu;
	}

	if (choice == 3)
	{
		system("cls");
		fnclean();
		Sleep(1500);

	}

	if (choice == 4)
	{
		system("cls");

		colorred();
		slow_print(" Current Supported Games: \n\n", 50);

		slow_print(" Fortnite (EAC + BE)\n\n", 50);

	}

	std::cout << skCrypt("\n\n Closing in ten seconds...");
	Sleep(10000);
	exit(0);
}

std::string tm_to_readable_time(tm ctx) {
	char buffer[80];

	strftime(buffer, sizeof(buffer), "%a %m/%d/%y %H:%M:%S %Z", &ctx);

	return std::string(buffer);
}

static std::time_t string_to_timet(std::string timestamp) {
	auto cv = strtol(timestamp.c_str(), NULL, 10); // long

	return (time_t)cv;
}

static std::tm timet_to_tm(time_t timestamp) {
	std::tm context;

	localtime_s(&context, &timestamp);

	return context;
}
