 #include <iostream>
 #include <string>
 using namespace std;
 
 #define SIZE 9
 
int num = 0;       //�������G�ഫ�᪺��
int point = 0;     //����
int out = 0;       //���X����
int out_sum = 0;   //�ֿn�X����
int base[4] = {0}; //�]�S���A�A0�S�W�L�H�B1�S�W���H�A�}�C���ޤ��O�����A0:���S, 1:�@�S, 2:�G�S, 3:�T�S

int getNum (string point) {
        if (point == "1B")
            return 1;
        else if (point == "2B")
            return 2;
        else if (point == "3B")
            return 3;
        else if (point == "HR")
            return 4;
        return 0;
};

 
 int main()
 {
 	int a[SIZE];
 	string input[SIZE][5];
 	char temp[3];
 	int b;
 	
 	for(int i=0; i<SIZE; i++)
 	{
 		//cout << "times: " ;
 		cin >> a[i] ;    //value between 1~5
 		for(int j=0; j<a[i]; j++) //j<a[i], means that give each player thier hit result(ex: 1B, 2B, FO, SO...etc)
 		{
 			cin >> temp; 
 			input[i][j] = temp;
		 }
	 }
	 cin >> b; //number of outs(1~27)
	 
	   //�p�����

    bool isOver = false;
    int index = 0;
    while (true)
    {
        for (int i = 0; i < SIZE; i++)
        {
            //�W�L�̫�@�����
            if (index > a[i])
            {
                isOver = true;
                break;
            }

            //�N�������G�ഫ���Ʀr
            num = getNum(input[i][index]);

            //�X��
            if (num == 0)
            {
                out_sum++;
                out++;
            }
            //�w��
            else
            {
                base[0] = 1; //�N�����̩�b���S
                for (int x = 3; x >= 0; x--)
                {
                    //�p�G�S�W���H
                    if (base[x] == 1)
                    {
                        //�^�쥻�S
                        if (x + num >= 4)
                        {
                            point++;
                        }
                        //���^�쥻�S
                        else
                        {
                            base[x + num] = 1;
                        }
                        base[x] = 0;
                    }
                }
            }
            //�X���ƹF�쵲������
            if (out_sum == b)
            {
                isOver = true;
                break;
            }

            //�F��T�ӥX���ơA�M�Ŷ]�S���A
            if (out == 3)
            {
                out = 0;
                base[0] = base[1] = base[2] = base[3] = 0;
            }
        }
        if (isOver)
        {
            break;
        }
        index++;
    }

    //�L�X���G
    printf("%d", point);

    return 0;
 }
