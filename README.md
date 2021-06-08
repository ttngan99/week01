# Week 01 - Tìm hiểu chung - Củng cố kiến thức nền tảng

## Lý thuyết

### Source-Control Management/Git: (cá nhân)

- Tìm hiều về SCM, cách sử dụng git.
- Các lệnh cơ bản và thường sử dụng trong git
- Git branch/Git checkout/pull push

### Microservice/Docker: (cá nhân)

- Tìm hiểu về cơ chế của Docker.
- Docker image.
- Docker container.
- Dockerfile.
- Docker compose

### Network/Firewall: (cá nhân)

- Firewall là gì? Tại sao cần phải có firewall.
- Cấu hình firewall trên linux/window như thế nào.
- Có nên tắt window defense/window firewall trên windows không?

### OS Kernel/Linux (nhóm)

- Các thành phần chính của OS
- Cơ chế khởi động của hệ điều hành (OS)
- Unix-like là gì, Linux Kernel, Window kernel, Darwin
- Phân biệt Docker vs OS vs Virtual Machine.
- Sử dụng bash/shell cơ bản: vi/vim/rm/ls/cd/touch/cat/expression/…
- Sử dụng Window Subsystem Linux trên Window như thế nào?

### Cloud Service (nhóm)

- PaaS/SaaS/AaaS
- Cloud vs On-Premise
- Các nhóm dịch vụ cloud: Cloud Storage/ Cloud Computing/ Cloud Networking (VPC)

### Mã hoá/Thuật toán

- Encryption/Description và Hasing
- Cơ chế mã hoá RSA/AES/DES và ứng dụng
- Base64
- SSL/TSL, lỗ hổng Heartbleed của SSL

## Thực hành

1/ Đăng ký sử dụng github để upload, quản lý các bài tập.

2/ Các cloud provider như Google Cloud, AWS, Alibaba Cloud, Digital Ocean,... cung cấp nhiều services miễn phí cho sinh viên. Hãy đăng ký sử dụng, quản lý 1 virtual machine (VM linux - Centos/Ubuntu, ...).

3/ Thực tập trên VM linux cài đặt Docker. Pull docker blog Ghost CMS và deploy lên VM.

> 3.1/ Sử dụng Dockerfile để build image thay vì pull docker image từ docker hub.

> 3.2/ Đăng ký tài khoản docker hub để push image lên hub.

> 3.3/ Sử dụng docker compose để compose application (Ghost cms) và Database cùng một file docker-compose.yml.

4/ Đăng ký và quản lý tên miền trên hostinger.vn (đăng ký đuôi .online 22.951 VNĐ).

5/ Trỏ tên miền vào blog đã đăng ký.

6/ Chỉ mở port cho application cần publish không mở toàn bộ port.

7/ Viết thuật toán encode và decode Base64 (không sử dụng thư viện). So sánh tốc độ encode/decode với một số thư viện đã có.

7/ Sử dụng Let’s encrypt để issue SSL cho blog vừa tạo. Cấu hình https cho web (optional).

8/ Làm slide powerpoint trình bày các nội dung trên.

## Ngày nộp: đến hết ngày 15/06/2021.

### Join vào org https://github.com/intern2021. Mỗi bạn sẽ tạo một repository trên org này để upload bài thực hành

### Yêu cầu: tất cả cấu hình cài đặt đều upload lên github. 
