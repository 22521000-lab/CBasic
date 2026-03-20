# 1. Khai báo trình biên dịch và flag
CC = gcc
CFLAGS = -Wall -Wextra -g

# 2. Danh sách các file object (.o) cần tạo
# Khi có thêm file mới (ví dụ engine.c), chỉ cần thêm engine.o vào đây
OBJS = main.o human.o

# 3. Tên file thực thi đầu ra
TARGET ?= my_program

# 4. Rule mặc định: chạy khi gõ 'make'
all: $(TARGET)

# 5. Cách tạo ra file thực thi từ các file object
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 6. Cách biên dịch file .c thành file .o
# % khớp với mọi tên file
%.o: %.c human.h
	$(CC) $(CFLAGS) -c $< -o $@
run: $(TARGET)
	./$(TARGET).exe
# 7. Lệnh dọn dẹp (gõ 'make clean')
clean:
	del /f *.o $(TARGET).exe
