#ifndef HUMAN_H
#define HUMAN_H
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
typedef struct someone_t someone_t;

/**
 * @brief kiểu dữ liệu định nghĩa cho thu nhập của một loại người
 * @note có thể là kí tự hoặc số nguyên
 */
typedef union 
{
    char *trom_xin_income;
    uint16_t cong_nhan_income;
} income_u;

/**
 * @brief Cấu trúc định nghĩa đại diện một người
 * @note Cấu trúc bao gồm loại người và thông tin loại đó
 */
struct someone_t
{
    char *type;                           /*!<loại người*/
    income_u income;                      /*!<thu nhập của loại người tương ứng*/
    void (*action)(someone_t * self);     /*!<con trỏ hàm hành động tương ứng*/
};

someone_t *create_human(char *type);
void cadge(someone_t *self);
void stole(someone_t *self);
void work(someone_t *self);
void init_human(someone_t *self);
someone_t *delete_human(someone_t *self);
#endif