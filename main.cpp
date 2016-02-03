/* -------------------------------------------------------------------------- */
/* Main.cpp																	  */
/*																			  */
/*																			  */
/* -------------------------------------------------------------------------- */
/* 番号		更新履歴							  日付		氏名			*/
/* -------------------------------------------------------------------------- */
/* 000		新規作成								2015/10/20	葛巻 大樹	  */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* includeファイル															  */
/* -------------------------------------------------------------------------- */
#include "define.h"
/* -------------------------------------------------------------------------- */
/* 定数定義																	  */
/* -------------------------------------------------------------------------- */
struct LIST{
	int next;
	char val[256];
};
void makelist(char * cp);
void print(void);
void search(char* sval);
/* -------------------------------------------------------------------------- */
/* グローバル変数															   */
/* -------------------------------------------------------------------------- */
int first=0;
int listsize=0;
struct LIST list[100];
/* -------------------------------------------------------------------------- */
/* プロトタイプ宣言(private)												  */
/* -------------------------------------------------------------------------- */
void makelist(char * cp){
	if (listsize!=0) {
		list[listsize-1].next=listsize;
	}
	strcpy(&list[listsize].val[0],cp);
	listsize++;
}
void print(void){
	int carent=first;
	cls();
	while (1) {
		printf("%s\n",&list[carent].val[0] );
		if(list[carent].next==-1)break;
		carent=list[carent].next;
	}
}
void search(char* sval){
	int carent=first;
	int temp;
	while (carent!=-1) {
		if (strcmp(sval,&list[carent].val[0])==0) {
			if (carent!=first) {
				list[temp].next=list[carent].next;
				list[carent].next=first;
				first=carent;
			}
			break;
		}else{
			temp=carent;
			// printf("△%s△\n",&list[temp].val[0] );
			carent=list[carent].next;
		}
	}
}
/* -------------------------------------------------------------------------- */
/* 関数名		: 															   */
/* 機能名	   	: 															   */
/* 機能概要	   : 															  */
/* 引数        : 					 : 				 : 							*/
/* 戻り値		: 					: 				: 						   */
/* 作成日		: 															   */
/* -------------------------------------------------------------------------- */
int main(int argc, char const *argv[]) {
	char buf[256];
	for (int i = 0; i < 100; i++) {
		list[i].next=-1;
	}
	// for (size_t i = 0; i < 100; i++) {
	// 	printf("%d %s\n",list[i].next,&list[i].val[0] );
	// }
	while (1) {
		if((scanf("%s", &buf[0]))==EOF) break;
		if (buf[0]=='-') {
			break;
		}
		makelist(&buf[0]);
	}
	print();
	while (1) {
		printf("探したい文字列を入力してください\n" );
		scanf("%s",&buf[0] );
		search(&buf[0]);
		// printf("first:%d\n",first);
		// for (int i = 0; i < 100; i++) {
		// 	printf("%d:%d %s\n",i,list[i].next,&list[i].val[0] );
		// }
		print();
	}

	return 0;
}
/* -------------------------------------------------------------------------- */
/* 				Copyright HAL College of Technology & Design				  */
/* -------------------------------------------------------------------------- */
