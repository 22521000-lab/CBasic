#include "human.h"

/**
  * @brief  Tạo một đối tượng người mới với type cho trước.
  * @note   Người dùng có trách nhiệm gọi hàm delete_human() để giải phóng bộ nhớ 
  *         được cấp phát bởi malloc().
  * @param  type: Loại người được tạo
  * @retval someone_t *
  */
someone_t *create_human(char *type)
{
    someone_t *new_human = (someone_t*)malloc(sizeof(someone_t));
    new_human->type = strdup(type);
    init_human(new_human);
    return new_human;
}

/**
  * @brief  hàm hành động của người anxin.
  * @param  self: con trỏ địa chỉ chứa người được truyền vào
  * @retval None
  */
void cadge(someone_t *self)
{
    printf("lam on lam phuoc\n");
}

/**
  * @brief  hàm hành động của người antrom.
  * @param  self: con trỏ địa chỉ chứa người được truyền vào
  * @retval None
  */
void stole(someone_t *self)
{
    printf("!!!\n");
}

/**
  * @brief  hàm hành động của người congnhan.
  * @param  self: con trỏ địa chỉ chứa người được truyền vào
  * @retval None
  */
void work(someone_t *self)
{
    printf("congnhanincome %d\n", self->income.cong_nhan_income);
}

/**
  * @brief  hàm khởi tạo thông tin cho một người sẽ dùng ở create_person
  * @param  self: con trỏ địa chỉ chứa người được truyền vào
  * @retval None
  */
void init_human(someone_t *self)
{
    if (0 == strcmp("anxin", self->type))
    {
        self->income.trom_xin_income = "tuytam";
        self->action = cadge;
    }
    else if (0 == strcmp("antrom", self->type))
    {
        self->income.trom_xin_income = "henxui";
        self->action = stole;
    }
    else
    {
        self->income.cong_nhan_income = 50000;
        self->action = work;
    }
}

/**
  * @brief  hàm giải phóng bộ nhớ 
  * @param  self: con trỏ địa chỉ chứa người được truyền vào
  * @retval None
  */
someone_t *delete_human(someone_t *self)
{
    if (self != NULL)
    {
    free(self);
    }
}