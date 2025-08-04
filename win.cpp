#include <windows.h>

// Identifiers for menu items and buttons
#define ID_FILE_EXIT 1
#define ID_BUTTON_TOPIC1 3
#define DS_WINDOW_CLASS "DataStructuresWindow"
#define ID_DS_ARRAYS     101
#define ID_DS_LINKEDLIST 102
#define ID_DS_STACKS     103
#define OOP_WINDOW_CLASS "OOPConceptsWindow"
#define ID_OOP_INHERITANCE   201
#define ID_OOP_POLYMORPHISM  202
#define ID_OOP_ABSTRACTION   203
#define ID_OOP_ENCAPSULATION 204

int screenWidth = GetSystemMetrics(SM_CXSCREEN);
int screenHeight = GetSystemMetrics(SM_CYSCREEN);

// Window Procedure
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static const char* topics[] = {
        "Data Structures", "Algorithms", "Memory Management", "OOP Concepts", "STL Containers",
        "Multithreading", "Smart Pointers", "Recursion & DP", "Sorting & Searching", "System Design"
    };

    switch (uMsg)
    {
    case WM_CREATE:
        MessageBox(hwnd, "Welcome to C++ Interview Preparation! by SHIV", "Greetings", MB_OK);
        for (int i = 0; i < 10; ++i)
        {
            CreateWindow("BUTTON", topics[i], WS_VISIBLE | WS_CHILD,
                         50, 50 + i * 40, 250, 30, hwnd,
                         (HMENU)(ID_BUTTON_TOPIC1 + i),
                         (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
        }
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == ID_FILE_EXIT)
        {
            PostQuitMessage(0);
        }
        else if (LOWORD(wParam) == ID_BUTTON_TOPIC1) // Data Structures Button
        {
            HWND dsHwnd = CreateWindowEx(0, DS_WINDOW_CLASS, "Data Structures Topics",
                                     WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                                     300, 250, NULL, NULL,
                                     (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

            if (dsHwnd)
            {
                ShowWindow(dsHwnd, SW_SHOW);
                UpdateWindow(dsHwnd);
            }
        }
        else if (LOWORD(wParam) == ID_BUTTON_TOPIC1 + 3) // OOP Concepts button
{
    HWND oopHwnd = CreateWindowEx(0, OOP_WINDOW_CLASS, "OOP Concepts",
                              WS_OVERLAPPEDWINDOW | WS_MAXIMIZE,
                              CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                              NULL, NULL,
                              (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

    if (oopHwnd)
    {
        ShowWindow(oopHwnd, SW_SHOW);
        UpdateWindow(oopHwnd);
    }
}

        else if (LOWORD(wParam) > ID_BUTTON_TOPIC1 && LOWORD(wParam) < ID_BUTTON_TOPIC1 + 10)
        {
            int index = LOWORD(wParam) - ID_BUTTON_TOPIC1;
            MessageBox(hwnd, topics[index], "Topic Selected", MB_OK);
        }
        break;
        

        case WM_ERASEBKGND:
{
    HDC hdc = (HDC)wParam;
    RECT rc;
    GetClientRect(hwnd, &rc);
    HBRUSH brush = CreateSolidBrush(RGB(0, 255, 0)); // Green
    FillRect(hdc, &rc, brush);
    DeleteObject(brush);
    return TRUE;
}


    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}


LRESULT CALLBACK DSWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static const char* topics[] = {
        "Arrays", "Linked Lists", "Stacks"};
    switch (uMsg)
    {
    case WM_CREATE:
        CreateWindow("BUTTON", "Arrays", WS_VISIBLE | WS_CHILD,
                     30, 30, 200, 30, hwnd, (HMENU)ID_DS_ARRAYS,
                     (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
        CreateWindow("BUTTON", "Linked Lists", WS_VISIBLE | WS_CHILD,
                     30, 70, 200, 30, hwnd, (HMENU)ID_DS_LINKEDLIST,
                     (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
        CreateWindow("BUTTON", "Stacks", WS_VISIBLE | WS_CHILD,
                     30, 110, 200, 30, hwnd, (HMENU)ID_DS_STACKS,
                     (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
        break;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_DS_ARRAYS:
            MessageBox(hwnd, "Arrays selected", "Data Structures", MB_OK);
            break;
        case ID_DS_LINKEDLIST:
            MessageBox(hwnd, "Linked Lists selected", "Data Structures", MB_OK);
            break;
        case ID_DS_STACKS:
            MessageBox(hwnd, "Stacks selected", "Data Structures", MB_OK);
            break;
        }
        break;

        case WM_ERASEBKGND:
{
    HDC hdc = (HDC)wParam;
    RECT rc;
    GetClientRect(hwnd, &rc);
    HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255)); // Blue
    FillRect(hdc, &rc, brush);
    DeleteObject(brush);
    return TRUE;
}


    case WM_DESTROY:
        DestroyWindow(hwnd); 
        break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

LRESULT CALLBACK OOPWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static HWND hOOPTextLabel = NULL;

    HWND hViewCodeButton = NULL; // Declare globally within the function


    switch (uMsg)
    {
    case WM_CREATE:
        CreateWindow("BUTTON", "Inheritance", WS_VISIBLE | WS_CHILD,
                     30, 30, 200, 30, hwnd, (HMENU)ID_OOP_INHERITANCE,
                     (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
        CreateWindow("BUTTON", "Polymorphism", WS_VISIBLE | WS_CHILD,
                     30, 70, 200, 30, hwnd, (HMENU)ID_OOP_POLYMORPHISM,
                     (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
        CreateWindow("BUTTON", "Abstraction", WS_VISIBLE | WS_CHILD,
                     30, 110, 200, 30, hwnd, (HMENU)ID_OOP_ABSTRACTION,
                     (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
        CreateWindow("BUTTON", "Encapsulation", WS_VISIBLE | WS_CHILD,
                     30, 150, 200, 30, hwnd, (HMENU)ID_OOP_ENCAPSULATION,
                     (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
        break;

    case WM_COMMAND:
        if (hOOPTextLabel)
    {
        DestroyWindow(hOOPTextLabel);
        hOOPTextLabel = NULL;
    }

    switch (LOWORD(wParam))
    {

        case 1005: // View Code button
            ShellExecute(NULL, "open", "inheritance.cpp", NULL, NULL, SW_SHOWNORMAL);
            break;

    case ID_OOP_INHERITANCE:
{
    hViewCodeButton = CreateWindow("BUTTON", "View Code",
    WS_VISIBLE | WS_CHILD | BS_OWNERDRAW,
    50, 550, 120, 30,
    hwnd, (HMENU)1005,
    (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);


    hOOPTextLabel = CreateWindow("STATIC",
        "Acquiring properties from one class to another class is known as inheritance.",
        WS_VISIBLE | WS_CHILD | SS_LEFT,
        50, 500, 1200, 30, hwnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
}
break;


    case ID_OOP_POLYMORPHISM:
        hOOPTextLabel = CreateWindow("STATIC",
            "A single entity can exist in more than one form is known as polymorphism.",
            WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 500, 1200, 30, hwnd, NULL,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
        break;

    // You can add more cases like Abstraction, Encapsulation etc.
    

        case ID_OOP_ABSTRACTION:
            hOOPTextLabel = CreateWindow("STATIC",
            "Representing essancial information and hiding the background details is known as data Abstraction.",
            WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 500, 1200, 30, hwnd, NULL,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
        break;
        case ID_OOP_ENCAPSULATION:
           hOOPTextLabel = CreateWindow("STATIC",
            "Binding function and data as single unit is known as Encapsulation.",
            WS_VISIBLE | WS_CHILD | SS_LEFT,
            50, 500, 1200, 30, hwnd, NULL,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
        break;
        }
        break;

        case WM_ERASEBKGND:
             {
            HDC hdc = (HDC)wParam;
            RECT rc;
            GetClientRect(hwnd, &rc);
            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0)); // Red
            FillRect(hdc, &rc, brush);
            DeleteObject(brush);
            return TRUE;
        }

case WM_DRAWITEM:
{
    LPDRAWITEMSTRUCT pDIS = (LPDRAWITEMSTRUCT)lParam;

    if (pDIS->CtlID == 1005) // View Code button
    {
        // Fill background with green
        HBRUSH hGreenBrush = CreateSolidBrush(RGB(0, 200, 0));
        FillRect(pDIS->hDC, &pDIS->rcItem, hGreenBrush);
        DeleteObject(hGreenBrush);

        // Draw button text
        SetBkMode(pDIS->hDC, TRANSPARENT);
        SetTextColor(pDIS->hDC, RGB(255, 255, 255)); // White text

        DrawText(pDIS->hDC, "View Code", -1, &pDIS->rcItem,
                 DT_CENTER | DT_VCENTER | DT_SINGLELINE);

        return TRUE;
    }
}
break;


    case WM_DESTROY:
        DestroyWindow(hwnd);
        break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASS wc = { };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "C++InterviewApp";

    WNDCLASS dsWc = { };
    dsWc.lpfnWndProc = DSWindowProc;
    dsWc.hInstance = hInstance;
    dsWc.lpszClassName = DS_WINDOW_CLASS;

    WNDCLASS oopWc = { };
    oopWc.lpfnWndProc = OOPWindowProc;
    oopWc.hInstance = hInstance;
    oopWc.lpszClassName = OOP_WINDOW_CLASS;

    RegisterClass(&oopWc);
    RegisterClass(&wc);
    RegisterClass(&dsWc);

    HMENU hMenu = CreateMenu();
    AppendMenu(hMenu, MF_STRING, ID_FILE_EXIT, "Exit");

    HWND hwnd = CreateWindowEx(
    0, "C++InterviewApp", "C++ Interview Preparation by SHIV",
    WS_POPUP | WS_VISIBLE, 0, 0,
    screenWidth, screenHeight,
    NULL, hMenu, hInstance, NULL);

    if (!hwnd) return 0;

    ShowWindow(hwnd, nCmdShow);

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
