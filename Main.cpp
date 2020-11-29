#include <iostream>
using namespace std;

#define NAME_SIZE 10             //�̸�
#define ID_SIZE 10               //�й�
#define STUDENT_MAX 100          //�л� ��
#define DEPARTMENT_SIZE 20       //�а�
#define PHONE_SIZE 20            //��ȭ��ȣ
#define PROFESSOR  10            //����
#define CONSULTING 10            //�������

struct Student
{
	//�л� �����͸� ������ ����ü
	char strName[NAME_SIZE];               //�̸�
	char strDepartment[DEPARTMENT_SIZE];   //�а�
	char strID[ID_SIZE];                   //�й�
	char strPhone[PHONE_SIZE];             //��ȭ��ȣ
	char professor[PROFESSOR];             //��������
	char consulting[CONSULTING];           //�������

	//��հ��� �������� ���� ������
	int DB;                                //DB ����
	int C;                                 //C���α׷��� ����
	int AI;                                //AI ����
	int ESP;                               //ESP ����
	int total;                             //�հ� ����
	double avg;                             //��� ����

};

double totalAvg(int count, Student st[]); 
void consultionCheck(char strProf[], int count, Student st[]); 

int main()
{
	Student StudentArr[STUDENT_MAX] = {}; 
	char strName[NAME_SIZE] = {};
	char strProf[NAME_SIZE] = {};
	char strDepartment[DEPARTMENT_SIZE] = {};
	char strID[ID_SIZE] = {};
	char strPhone[PHONE_SIZE] = {};
	char professor[PROFESSOR] = {};
	char consulting[CONSULTING] = {};

	int StudentCount = 0;

	int Menu = NULL;

	while (true)
	{
		// �޴� ���
		cout << "\n ======== <����> �޴��� �Է����ּ���. ========" << endl;
		cout << " 1. �л� ���  " << endl;
		cout << " 2. �л� �˻�  " << endl;
		cout << " 3. �л� ����  " << endl;
		cout << " 4. ���������л� ����Ʈ  " << endl;
		cout << " 5. �������� ��� ���� Ȯ��  " << endl;
		cout << " 6. ���α׷� ���� \n\n " << endl;


		cout << " �޴��� �����ϼ��� : ";

		
		cin >> Menu;

		while(cin.fail()) {		
			cout << "\n======== �߸��Է��߽��ϴ�. �޴��� �ٽ� �Է��� �ּ���. =========" << endl;
			cout << "\n======== <����> �޴��� �Է����ּ���. ========" << endl;
			cout << " 1. �л� ���  " << endl;
			cout << " 2. �л� �˻�  " << endl;
			cout << " 3. �л� ����  " << endl;
			cout << " 4. ���������л� ����Ʈ  " << endl;
			cout << " 5. �������� ��� ���� Ȯ��  " << endl;
			cout << " 6. ���α׷� ���� \n\n " << endl;

			cin.clear();
			cin.ignore();
			cin >> Menu;
		}

		switch (Menu) 
		{
		case 1:
		{
			system("cls");
			//�л� ���
			cout << "\n======== <���> �л������� �Է����ּ���. ========" << endl;

			if (StudentCount == STUDENT_MAX) {
				cout << "\n======== �Է°����� �л� �����͸� �ʰ��Ͽ����ϴ�. ========" << endl;
				break;
			}

			
			cout << "�̸� : ";
			cin >> StudentArr[StudentCount].strName;


			cin.ignore(1024, '\n');          

			cout << "�й� : ";
			cin.getline(StudentArr[StudentCount].strID, ID_SIZE);

			

			cout << "�а� : ";
			cin.getline(StudentArr[StudentCount].strDepartment, DEPARTMENT_SIZE);

			cout << "��ȭ��ȣ : ";
			cin.getline(StudentArr[StudentCount].strPhone, PHONE_SIZE);

			cout << "�������� : ";
			cin.getline(StudentArr[StudentCount].professor, PROFESSOR);

			
			cout << "�������(T,F) : ";
			cin.getline(StudentArr[StudentCount].consulting, PROFESSOR);
			*StudentArr[StudentCount].consulting = toupper(*StudentArr[StudentCount].consulting); 
			//�Է¹��� ��������� �ҹ��ڸ� �빮�ڷ� �ٲ��ִ� �ڵ�

			cout << "DB ���� : ";
			cin >> StudentArr[StudentCount].DB;

			cout << "C ���α׷��� ���� : ";
			cin >> StudentArr[StudentCount].C;

			cout << "AI ���� : ";
			cin >> StudentArr[StudentCount].AI;

			cout << "ESP ���� : ";
			cin >> StudentArr[StudentCount].ESP;

			//������ ���� ���Ѵ�.
			StudentArr[StudentCount].total =
				StudentArr[StudentCount].DB +
				StudentArr[StudentCount].C +
				StudentArr[StudentCount].AI +
				StudentArr[StudentCount].ESP;
			
			//������ ����� ���Ѵ�.
			StudentArr[StudentCount].avg =
				StudentArr[StudentCount].total / 4.0;

			StudentCount++;
			cout << "======== �л� �߰��� �Ϸ�Ǿ����ϴ�. ========\n" << endl;

			break;
		}
		case 2:
		{
			system("cls");
			//�л� �˻�
			cout << "\n======== <�˻�> �˻� �� �л��� �й��� �Է����ּ���. ========\n" << endl;
			bool seachCheck = false;

			cin.ignore(1024, '\n');
			cout << "�˻� �� �л��� �й��� �Է� : ";
			cin.getline(strID, ID_SIZE);

			for (int i = 0; i < StudentCount; ++i)
			{				
				if (strcmp(StudentArr[i].strID,strID)==0)
				{
					cout << "\n�̸�:" << StudentArr[i].strName;
					cout << "\t�а�:" << StudentArr[i].strDepartment;
					cout << "\t�й�:" << StudentArr[i].strID;
					cout << "\t��ȭ��ȣ:" << StudentArr[i].strPhone;
					cout << "\t ��������:" << StudentArr[i].professor;
					cout << "\t �������:" << StudentArr[i].consulting;
					cout << "\t DB ����:" << StudentArr[i].DB;
					cout << "\tC ���α׷��� ����:" << StudentArr[i].C;
					cout << "\tAI ����:" << StudentArr[i].AI;
					cout << "\tESP ����:" << StudentArr[i].ESP;
					cout << "\t����:" << StudentArr[i].avg<< "\n";
					seachCheck = true;  
				}
			}
			if (!seachCheck) {
				cout << "\n=======�˻��� �л������� �����ϴ�.=======\n" << endl;
			}
			seachCheck = false;
			break; 
		}
		case 3:
		{
			system("cls");
			//�л� ����
			cout << "\n======== <����> ������ �л��� �й��� �Է����ּ���. ========\n" << endl;
			
			bool deleteCheck = false;
			cin.ignore(1024, '\n');
			cout << "������ �л��� �й��� �Է� : ";
			cin.getline(strID, ID_SIZE);

			for (int i = 0; i < StudentCount; ++i)
			{
				if (strcmp(StudentArr[i].strID, strID) == 0)
				{
					for (int j = i; j < StudentCount - 1; ++j)
					{
						StudentArr[i] = StudentArr[i + 1];
					}
					--StudentCount;
					cout << "\n======= �ش� �й��� �л������� �����Ǿ����ϴ�. ========" << endl;
					deleteCheck = true;
				}
			}
			if (!deleteCheck) {
				cout << "\n=======�ش� �й��� �л������� �����ϴ�.=======\n" << endl;
			}
			deleteCheck = false;
			break;
		}
		case 4:
		{	
			system("cls");
			//���������л� ����Ʈ
			bool avgCheck = false;
			cout << endl;
			for (int i = 0; i < StudentCount; i++) {
				if (StudentArr[i].avg < totalAvg(StudentCount, StudentArr)) {
					cout<<StudentArr[i].strName<<" �л��� ����� "<<StudentArr[i].avg<<" �� ��ü�����"<<totalAvg(StudentCount,StudentArr)<<" ���� �����ϴ�.\n" << endl;
					avgCheck = true;
				}
			}	
			if (!avgCheck) {
				cout << "\n=======�������� �л��� �����ϴ�.=======\n" << endl;
			}
			avgCheck = false; 

			break;
		}
	
		case 5:
		{
			system("cls");
			//�������� ��� ���� Ȯ��
			cout << "\n======== ���������� �̸��� �Է����ּ���. ========\n" << endl;
			cin.ignore(1024, '\n');
			cout << "�������� �̸��� �˻��ϼ���. : ";
			cin.getline(strProf, NAME_SIZE);
			consultionCheck(strProf, StudentCount, StudentArr);
			break;
		}
		case 6:
		{		
			//���α׷� ����
			cout << "\n======== ���α׷��� ����Ǿ����ϴ�. ========\n\n" << endl;
			return 0;
		}
		default: {
			cout << "\n======== �߸��Է��߽��ϴ�. �޴��� �ٽ� �Է��� �ּ���. ========" << endl;
		}			
		Menu = NULL;
		}
	}
}

double totalAvg(int count, Student st[]) {
	double all_avg = 0.0;
	for (int i = 0; i <= count; i++) {
		all_avg += st[i].total;
	}
	return (all_avg / count+1);
}

void consultionCheck(char strProf[], int count, Student st[])
{
	bool profCheck = false;

	cout << endl;

	for (int i = 0; i <= count; i++)
	{
		if (strcmp(st[i].professor, strProf) == 0) {
			cout << st[i].professor << " ���������� " << st[i].strName << " �л� ��������� [ " << st[i].consulting << " ] �Դϴ�." << endl;
			profCheck = true;
		}
	}
	if (!profCheck) {
		cout << "\n======== �ش� ���������� �����ϴ�. ========" << endl;
	}
}