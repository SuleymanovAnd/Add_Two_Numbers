// Add Two Numbers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* SumList = new ListNode;
        int count = 0;
        int plus = 0;
        for (int i = 0; !(temp1 == nullptr) || !(temp2 == nullptr); i++) {
            if (i == 0) {
                if (temp1 != nullptr && temp2 != nullptr)
                {
                    ListNode* temp = new ListNode((temp1->val + temp2->val + plus) % 10);
                    if (temp1->val + temp2->val + plus >= 10) plus = 1;
                    else plus = 0;
                    SumList = temp;
                }
                else if (temp1 != nullptr) {
                    ListNode* temp = new ListNode((temp1->val + plus) % 10);
                    if (plus + temp1->val >= 10) plus = 1;
                    else plus = 0;
                    SumList = temp;
                }
                else {
                    ListNode* temp = new ListNode((temp2->val + plus) % 10);
                    if (temp2->val + plus >= 10) plus = 1;
                    else plus = 0;
                    SumList = temp;
                }
            }
            else {
                if (temp1 != nullptr && temp2 != nullptr)
                {
                    ListNode* temp = new ListNode(((temp1->val + temp2->val + plus) % 10), SumList);
                    if (temp1->val + temp2->val + plus >= 10) plus = 1;
                    else plus = 0;
                    SumList = temp;
                }
                else if (temp1 != nullptr) {
                    ListNode* temp = new ListNode(((temp1->val + plus) % 10), SumList);
                    if (temp1->val + plus >= 10) plus = 1;
                    else plus = 0;
                    SumList = temp;
                }
                else {
                    ListNode* temp = new ListNode(((temp2->val + plus) % 10), SumList);
                    if (plus + temp2->val >= 10) plus = 1;
                    else plus = 0;
                    SumList = temp;
                }
            }\
                if (temp1 != nullptr) temp1 = temp1->next;
            if (temp2 != nullptr) temp2 = temp2->next;
            if (temp1 == nullptr && temp2 == nullptr && plus) {
                ListNode* temp = new ListNode(((plus) % 10), SumList);
                SumList = temp;
            }
            count = i;
            if (temp1 == nullptr && temp2 == nullptr && plus) count++;
        }
        ListNode* revertSumList = new ListNode;
        for (int i = 0; count != -1; i++) {
            if (i == 0) {
                ListNode* temp = new ListNode(SumList->val);
                revertSumList = temp;
                SumList = SumList->next;
            }
            else {
                ListNode* temp = new ListNode(SumList->val, revertSumList);
                revertSumList = temp;
                SumList = SumList->next;
            }
            count--;
        }


        return  revertSumList;
    }
};

int main()
{
    //ListNode L1(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9,new ListNode(9, new ListNode(9)))))));
    //ListNode L2(9, new ListNode(9, new ListNode(9, new ListNode(9))));
    ListNode L1(2, new ListNode(4, new ListNode(3)));
    ListNode L2(5, new ListNode(6, new ListNode(4)));
    Solution a1;
    a1.addTwoNumbers(&L1, &L2);

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
