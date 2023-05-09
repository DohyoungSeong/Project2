#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm* time1, * time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main() {
	filestat1();
	filestat2();
	filetime1();
	filetime2();
	sizecmp();
	blockcmp();
	datecmp();
	timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1() //2018202054 김찬희
{
	stat("text1", &stat1);
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2() //2018202054 김찬희
{
	stat("text2", &stat2);
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1() {

}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2() {

}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp() //2018202054 김찬희
{
	printf("size compare\n");
	if (stat1.st_size > stat2.st_size) {
		printf("text 1 is bigger\n\n");
	}
	else if (stat1.st_size < stat2.st_size) {
		printf("text 2 is bigger\n\n");
	}
	else {
		printf("sizes are equal\n\n");
	}
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp() {

}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(void)//2018202054 김찬희
{
	int t1_mon, t1_day, t2_mon, t2_day;
	int t1_year, t2_year;

	time1 = localtime(&stat1.st_mtime);
	t1_mon = time1->tm_mon;
	t1_day = time1->tm_mday;
	t1_year = time1->tm_year;

	time2 = localtime(&stat2.st_mtime);
	t2_mon = time2->tm_mon;
	t2_day = time2->tm_mday;
	t2_year = time2->tm_year;

	printf("date compare\n");
	if (t1_year < t2_year) {
		printf("text1 is early\n\n");
	}
	else if (t1_year > t2_year) {
		printf("text2 is early\n\n");
	}
	else {
		if (t1_mon < t2_mon) {
			printf("text1 is early\n\n");
		}
		else if (t1_mon > t2_mon) {
			printf("text2 is early\n\n");
		}
		else {
			if (t1_day < t2_day) {
				printf("text1 is early\n\n");
			}
			else if (t1_day > t2_day) {
				printf("text2 is early\n\n");
			}
			else printf("same date\n\n");
		}
	}
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp() {

}