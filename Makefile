# Khai báo trình biên dịch và flag
CC = gcc
CFLAGS = -Wall -Wextra -g -MMD

# Danh sách các file object  .c -> .o
OBJS = main.o human.o

# Tên file thực thi (Thêm .exe cho Windows để đồng nhất)
TARGET = my_program.exe

# Rule mặc định
all: $(TARGET)

# Link các file object thành file thực thi
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Biên dịch file .c thành .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Tự động chèn các file phụ thuộc (.d) do GCC tạo ra
-include $(OBJS:.o=.d)

# Rule chạy chương trình
run: $(TARGET)
	./$(TARGET)

# 7. Lệnh dọn dẹp
clean:
	del /f /q *.o *.d $(TARGET)
.PHONY: all run clean
