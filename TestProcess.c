#include<windows.h>
#include<stdio.h>
int main(){
	STARTUPINFO si; //cấu trúc chứa các thông tin cấu hình khi khởi động một tiến trình, ví dụ như cửa sổ, thư mục làm việc, v.v.
	PROCESS_INFORMATION pi; //Lưu trữ thông tin về tiến trình và luồng được tạo ra bởi CreateProcess.
	ZeroMemory(&si, sizeof(si)); //Hàm này được sử dụng để tạo một tiến trình mới. Tham số đầu tiên là tên của chương trình thực thi (trong trường hợp này là "Child.exe"), các tham số còn lại cung cấp các quyền truy cập, thuộc tính bảo mật, cách tiến trình được thừa kế các handles, các cờ điều khiển tiến trình, và đường dẫn thư mục làm việc.
	si.cb = sizeof(si);

	CreateProcess("Child.exe", NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	WaitForSingleObject(pi.hProcess, 10000); //INFINITE

	TerminateProcess(pi.hProcess, 0); //Hàm này dùng để kết thúc một tiến trình một cách bất ngờ. Tham số thứ hai là mã kết thúc mà tiến trình trả về khi kết thúc.
	CloseHandle(pi.hProcess); //Đóng handle mà CreateProcess đã tạo ra và giải phóng tài nguyên mà hệ điều hành đã cấp phát cho các handles này.
	CloseHandle(pi.hThread);
	return 0;
}