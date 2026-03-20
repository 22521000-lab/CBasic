/**
 ******************************************************************************
  * @file           : main.c
  * @brief          : Thực hành code C basic (áp dụng các coding convention)
 ******************************************************************************
 * 
 * Đề bài: Có 3 kiểu người: ăn xin, ăn trộm và công nhân. 
 * Định nghĩa một kiểu someone_t là một struct đại diện cho 1 người gồm các trường sau:
 * - type: là một chuỗi kí tự lưu kiểu người: "anxin", "antrom", "congnhan"
 * - income: là một trường lưu thông tin thu nhập của người đó. Nếu type:
 * + anxin: thì income là chuỗi kí tự có giá trị "tuytam"
 * + antrom: thì income là chuỗi kí tự có giá trị "henxui"
 * + congnhan: thì income là số nguyên 2 bytes có giá trị là 500000
 * - action: là một con trỏ hàm (với biến đầu vào có kiểu someone_t) trỏ tới công việc của mỗi người.  
 * Nếu type:
 * + anxin: thực hiện hàm cadge():n ra chuỗi "lam on lam phuoc"
 * + antrom: thực hiện hàm stole(): in ra chuỗi "!!!"
 * + congnhan: thực hiện hàm work(): in ra income của người này
 * Hàm main() thực hiện việc sau:
 * - Tạo ngẫu nhiên N người thuộc có kiểu someone_t
 * - lưu vào mảng có kích thước MAX_PEOPLE(cần được define). 
 * - Duyệt mảng trên và thực hiện hàm action của mỗi người
 * - Các chuỗi đầu ra được in lần lượt vào file "output.txt"
 * 
 */

#include"main.h"
#include"human.h"

#define MAX_PEOPLE 50

/**
  * @brief  hàm tạo một mảng động chứa địa chỉ của phần tử người
  * @param  people_number: số lượng người
  * @retval None
  */
void create_people_array(someone_t **people,int people_number)
{
    int i;
    for (i = 0; i < people_number;i++)
    {
        int type = rand() % 3;   /*rand 0 - 2*/      
        switch (type)
        {
        case 0:
        people[i] = create_human("anxin"); 
        break;
        case 1:
        people[i] = create_human("antrom");
        break;
        case 2:
        people[i] = create_human("congnhan");
        break;
        default:
            people[i] = create_human("anxin");
            break;
        }
    }
}
int main()
{
    srand(time(NULL));

    int i;
    int people_number;                                 /*só lượng người khởi tạo*/
    people_number = rand() % (MAX_PEOPLE - 1 + 1) + 1; /*rand() max 50 min 1*/
    someone_t **people = calloc(people_number, sizeof(someone_t*));
    create_people_array(people, people_number);    /*tạo mảng động*/
    
    FILE *file = fopen("output.txt", "w");
    for (i = 0; i < people_number;i++)                 /*duyệt mảng và thực hiện action*/
    {
        fprintf(file, "people la %s \t", people[i]->type);
        if (people[i]->action != NULL)
        {
            people[i]->action(people[i], file);
        }
    }

    for (i = 0; i < people_number; i++) {             /*Giải phóng vùng nhớ đã cấp phát*/
        delete_human(people[i]); 
    }
    free(people);

    return 0;
}