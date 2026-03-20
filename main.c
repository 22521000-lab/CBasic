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
    
    for (i = 0; i < people_number;i++)                 /*duyệt mảng và thực hiện action*/
    {
        printf("people la %s \t", people[i]->type);
        if (people[i]->action != NULL)
        {
            people[i]->action(people[i]);
        }
    }

    for (i = 0; i < people_number; i++) {             /*Giải phóng vùng nhớ đã cấp phát*/
        delete_human(people[i]); 
    }
    free(people);

    return 0;
}