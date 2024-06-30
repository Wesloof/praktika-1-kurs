#include "MyForm.h"
#include <Windows.h>
#include <iostream>
#include <ctime>
#include <fstream>
#include <locale.h>

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace std;
using namespace Project1;

const int dimension = 10000;
int arr[dimension] = { 0 };

System::Void Project1::MyForm::RandArr(int* a) {
    srand(time(0));
    for (int i = 0; i < dimension; i++) {
        a[i] = (rand() % 10001) - 5000;
    }

    numbers->Items->Clear();
    for (int i = 0; i < dimension; i++)
    {
        numbers->Items->Add(a[i]);
    }
}

void readfile(int* array, string path)
{
    fstream f;
    f.open(path, fstream::in | fstream::out);

    for (int i = 0; i < dimension; i++)
        f << array[i] << endl;

    f.close();
}
System::Void Project1::MyForm::BubbleSort(int* b) {
    int start = clock();
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension - 1; j++) {
            if (b[j] < b[j + 1]) {
                int t = b[j];
                b[j] = b[j + 1];
                b[j + 1] = t;
            }
        }
    }
    int end = clock();
    label1->Text = "Время работы:" + (double)(end - start) / CLOCKS_PER_SEC;
    numbers->Items->Clear();
    for (int i = 0; i < dimension; i++)
    {
        numbers->Items->Add(b[i]);
    }
}

inline System::Void Project1::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
    
    RandArr(arr);
    readfile(arr, "../test.txt");
}

inline System::Void Project1::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
    BubbleSort(arr);
    readfile(arr, "../sort.txt");
}

inline System::Void Project1::MyForm::checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    if (checkBox1->Checked == true) {
        label1->Visible = true;
    }
    else {
        label1->Visible = false;
    }
    
}

inline System::Void Project1::MyForm::listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}

[STAThreadAttribute]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MyForm);
    return 0;
}