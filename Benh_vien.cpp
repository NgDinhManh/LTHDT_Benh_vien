#include <bits/stdc++.h>

using namespace std;

// Mo file doc du lieu
ifstream file_input("du_lieu_vao.txt", ios::in);
ifstream file_input_chuyen_vien("du_lieu_chuyen_vien.txt", ios::in);
// Mo file ghi du lieu
ofstream file_output("du_lieu_ra.txt", ios::out);

// Lop benh_nhan quan ly benh nhan cua benh vien
class benh_nhan{
	protected:
		string ma_ho_so;
		string ho_ten;
		string ngay_sinh;
		string gioi_tinh;
		string chuan_doan_benh;
	public:
		benh_nhan(){}
		
		// Lay du lieu benh nhan
		string get_ma_ho_so(){
			return ma_ho_so;
		}
		string get_ho_ten(){
			return ho_ten;
		}
		string get_ngay_sinh(){
			return ngay_sinh;
		}
		string get_gioi_tinh(){
			return gioi_tinh;
		}
		string get_chuan_doan_benh(){
			return chuan_doan_benh;
		}

		// Sua du lieu benh nhan
		void set_ma_ho_so(string ma_ho_so){
			this->ma_ho_so = ma_ho_so;
		}
		void set_ho_ten(string ho_ten){
			this->ho_ten = ho_ten;
		}
		void set_ngay_sinh(string ngay_sinh){
			this->ngay_sinh = ngay_sinh;
		}
		void set_gioi_tinh(string gioi_tinh){
			this->gioi_tinh = gioi_tinh;
		}
		void set_chuan_doan_benh(string chuan_doan_benh){
			this->chuan_doan_benh = chuan_doan_benh;
		}

		// Nhap benh nhan tu ban phim
		void nhap(){
			cout << "Ma ho so: ";
			getline(cin, ma_ho_so);
			cout << "Ho ten: ";
			getline(cin, ho_ten);
			cout << "Ngay sinh: ";
			getline(cin, ngay_sinh);
			cout << "Gioi tinh: ";
			getline(cin, gioi_tinh);
			cout << "Chuan doan benh: ";
			getline(cin, chuan_doan_benh);
		}
		// Nhap benh nhan tu file
		void file_nhap(){
			getline(file_input, ma_ho_so);
			getline(file_input, ho_ten);
			getline(file_input, ngay_sinh);
			getline(file_input, gioi_tinh);
			getline(file_input, chuan_doan_benh);
		}
		// Xuat benh nhan ra man hinh
		void xuat(){
			cout << "|" << setw(14) << ma_ho_so << " |";
			cout << setw(23) << ho_ten << " |" ;
			cout << setw(12) << ngay_sinh << " |";
			cout << setw(10) << gioi_tinh << " |";
			cout << setw(37) << chuan_doan_benh << " |";
		}
		// Xuat benh nhan vao file
		void file_xuat(){
			file_output << "|" << setw(14) << ma_ho_so << " |";
			file_output << setw(23) << ho_ten << " |" ;
			file_output << setw(12) << ngay_sinh << " |";
			file_output << setw(10) << gioi_tinh << " |";
			file_output << setw(37) << chuan_doan_benh << " |";
		}
};

// Lop benh_nhan_noi_tru quan ly benh nhan noi tru
class benh_nhan_noi_tru : public benh_nhan{
	protected:
		string ngay_nhap_vien;
		string ngay_ra_vien;
		string ten_khoa;
		string so_giuong;
	public:
		benh_nhan_noi_tru(){}

		// Lay du lieu banh nhan
		string get_ngay_nhap_vien(){
			return ngay_nhap_vien;
		}
		string get_ngay_ra_vien(){
			return ngay_ra_vien;
		}
		string get_ten_khoa(){
			return ten_khoa;
		}
		string get_so_giuong(){
			return so_giuong;
		}

		// Sua du lieu banh nhan
		void set_ngay_nhap_vien(string ngay_nhap_vien){
			this->ngay_nhap_vien = ngay_nhap_vien;
		}
		void set_ngay_ra_vien(string ngay_ra_vien){
			this->ngay_ra_vien = ngay_ra_vien;
		}
		void set_ten_khoa(string ten_khoa){
			this->ten_khoa = ten_khoa;
		}
		void set_so_giuong(string so_giuong){
			this->so_giuong = so_giuong;
		}

		// Nhap benh nhan noi tru tu ban phim
		void nhap(){
			benh_nhan::nhap();
			cout << "Ngay nhap vien: ";
			getline(cin, ngay_nhap_vien);
			cout << "Ngay ra vien: ";
			getline(cin, ngay_ra_vien);
			cout << "Ten khoa: ";
			getline(cin, ten_khoa);
			cout << "So giuong ";
			getline(cin, so_giuong);
		}
		// Nhap benh nhan noi tru tu file
		void file_nhap(){
			benh_nhan::file_nhap();
			getline(file_input, ngay_nhap_vien);
			getline(file_input, ngay_ra_vien);
			getline(file_input, ten_khoa);
			getline(file_input, so_giuong);
		}
		// Xuat benh nhan noi tru ra man hinh
		void xuat(){
			benh_nhan::xuat();
			cout << setw(15) << ngay_nhap_vien << " |";
			cout << setw(15) << ngay_ra_vien << " |";
			cout << setw(24) << ten_khoa << " |";
			cout << setw(10) << so_giuong << " |" << endl;
		}
		// Xuat benh nhan noi tru vao file
		void file_xuat(){
			benh_nhan::file_xuat();
			file_output << setw(15) << ngay_nhap_vien << " |";
			file_output << setw(15) << ngay_ra_vien << " |";
			file_output << setw(24) << ten_khoa << " |";
			file_output << setw(10) << so_giuong << " |" << endl;
		}
		friend void danh_sach_noi_tru(benh_nhan_noi_tru *noi_tru, int so_noi_tru);
		friend void them_benh_nhan(benh_nhan_noi_tru* &noi_tru, int &so_noi_tru);
};
// Danh sach benh nhan noi tru ra man hinh
void danh_sach_noi_tru(benh_nhan_noi_tru *noi_tru, int so_noi_tru){
	cout << "                                                                       BENH NHAN NOI TRU\n";
	cout << " _________________________________________________________________________________________________________________________________________________________________________________ \n";
	cout << "|    Ma ho so   |       Ho va ten        |  Ngay sinh  | Gioi tinh |           Chuan doan benh            | Ngay nhap vien |  Ngay ra vien  |         Ten khoa        | So giuong |\n";
	cout << "|---------------|------------------------|-------------|-----------|--------------------------------------|----------------|----------------|-------------------------|-----------|\n";
	for(int i=0; i<so_noi_tru; i++){
		noi_tru[i].xuat();
	}
	cout << "|_______________|________________________|_____________|___________|______________________________________|________________|________________|_________________________|___________|\n";
	cout << endl;
}
// Them benh nhan ngoai tru
void them_benh_nhan(benh_nhan_noi_tru* &noi_tru, int &so_noi_tru){
	int new_so_noi_tru = so_noi_tru + 1;
	benh_nhan_noi_tru *tmp_noi_tru = new benh_nhan_noi_tru[new_so_noi_tru];

	for(int i=0; i<so_noi_tru; i++){
		tmp_noi_tru[i] = noi_tru[i];
	}

	cout << "Them benh nhan noi tru:\n";
	cout << "Ma ho so: ";
	getline(cin, tmp_noi_tru[new_so_noi_tru - 1].ma_ho_so);
	for(int i=0; i<so_noi_tru; i++){
		if(tmp_noi_tru[i].ma_ho_so == tmp_noi_tru[new_so_noi_tru - 1].ma_ho_so){
			cout << "Ma ho so da ton tai.\n";
			return;
		}
	}
	cout << "Ho ten: ";
	getline(cin, tmp_noi_tru[new_so_noi_tru - 1].ho_ten);
	cout << "Ngay sinh: ";
	getline(cin, tmp_noi_tru[new_so_noi_tru - 1].ngay_sinh);
	cout << "Gioi tinh: ";
	getline(cin, tmp_noi_tru[new_so_noi_tru - 1].gioi_tinh);
	cout << "Chuan doan benh: ";
	getline(cin, tmp_noi_tru[new_so_noi_tru - 1].chuan_doan_benh);
	cout << "Ngay nhap vien: ";
	getline(cin, tmp_noi_tru[new_so_noi_tru - 1].ngay_nhap_vien);
	cout << "Ngay ra vien: ";
	getline(cin, tmp_noi_tru[new_so_noi_tru - 1].ngay_ra_vien);
	cout << "Ten khoa: ";
	getline(cin, tmp_noi_tru[new_so_noi_tru - 1].ten_khoa);
	cout << "So giuong: ";
	getline(cin, tmp_noi_tru[new_so_noi_tru - 1].so_giuong);

	delete[] noi_tru;
	noi_tru = tmp_noi_tru;
	so_noi_tru = new_so_noi_tru;

	cout << "  ***  Them thanh cong  ***\n";
}

// Lop benh_nhan_ngoai_tru quan ly benh nhan ngoai tru
class benh_nhan_ngoai_tru : public benh_nhan{
	protected:
		string ngay_kham;
		string so_bhyt;
		string ma_toa_thuoc;
	public:
		benh_nhan_ngoai_tru(){}

		// Lay du lieu benh nhan
		string get_ngay_kham(){
			return ngay_kham;
		}
		string get_so_bhyt(){
			return so_bhyt;
		}
		string get_ma_toa_thuoc(){
			return ma_toa_thuoc;
		}

		// Sua du lieu benh nhan
		void set_ngay_kham(string ngay_kham){
			this->ngay_kham = ngay_kham;
		}
		void set_so_bhyt(string so_bhyt){
			this->so_bhyt = so_bhyt;
		}
		void set_ma_toa_thuoc(string ma_toa_thuoc){
			this->ma_toa_thuoc = ma_toa_thuoc;
		}

		// Nhap benh nhan ngoai tru tu ban phim
		void nhap(){
			benh_nhan::nhap();
			cout << "Ngay kham: ";
			getline(cin, ngay_kham);
			cout << "So BHYT: ";
			getline(cin, so_bhyt);
			cout << "Ma tao thuoc: ";
			getline(cin, ma_toa_thuoc);
		}
		// Nhap benh nhan ngoai tru tu file
		void file_nhap(){
			benh_nhan::file_nhap();
			getline(file_input, ngay_kham);
			getline(file_input, so_bhyt);
			getline(file_input, ma_toa_thuoc);
		}
		// Xuat benh nhan ngoai tru ra man hinh
		void xuat(){
			benh_nhan::xuat();
			cout << setw(15) << ngay_kham << " |";
			cout << setw(18) << so_bhyt << " |";
			cout << setw(13) << ma_toa_thuoc << " |" << endl; 
		}
		// Xuat benh nhan ngoai tru vao file
		void file_xuat(){
			benh_nhan::file_xuat();
			file_output << setw(15) << ngay_kham << " |";
			file_output << setw(18) << so_bhyt << " |";
			file_output << setw(13) << ma_toa_thuoc << " |" << endl; 
		}
		friend void danh_sach_ngoai_tru(benh_nhan_ngoai_tru *ngoai_tru, int so_ngoai_tru);
		friend void them_benh_nhan(benh_nhan_ngoai_tru* &ngoai_tru, int &so_ngoai_tru);
};
// Danh sach benh nhan ngoai tru ra man hinh
void danh_sach_ngoai_tru(benh_nhan_ngoai_tru *ngoai_tru, int so_ngoai_tru){
	cout << "                                                                     BENH NHAN NGOAI TRU\n";
	cout << " _____________________________________________________________________________________________________________________________________________________________ \n";
	cout << "|    Ma ho so   |       Ho va ten        |  Ngay sinh  | Gioi tinh |           Chuan doan benh            |   Ngay kham    |      So BHYT      | Ma toa thuoc |\n";
	cout << "|---------------|------------------------|-------------|-----------|--------------------------------------|----------------|-------------------|--------------|\n";
	for(int i=0; i<so_ngoai_tru; i++){
		ngoai_tru[i].xuat();
	}
	cout << "|_______________|________________________|_____________|___________|______________________________________|________________|___________________|______________|\n";
	cout << endl;
}
// Them benh nhan ngoai tru
void them_benh_nhan(benh_nhan_ngoai_tru* &ngoai_tru, int &so_ngoai_tru){
	int new_so_ngoai_tru = so_ngoai_tru + 1;
	benh_nhan_ngoai_tru *tmp_ngoai_tru = new benh_nhan_ngoai_tru[new_so_ngoai_tru];

	for(int i=0; i<so_ngoai_tru; i++){
		tmp_ngoai_tru[i] = ngoai_tru[i];
	}

	cout << "Them benh nhan ngoai tru:\n";
	cout << "Ma ho so: ";
	getline(cin, tmp_ngoai_tru[new_so_ngoai_tru - 1].ma_ho_so);
	for(int i=0; i<so_ngoai_tru; i++){
		if(tmp_ngoai_tru[i].ma_ho_so == tmp_ngoai_tru[new_so_ngoai_tru - 1].ma_ho_so){
			cout << "Ma ho so da ton tai.\n";
			return;
		}
	}
	cout << "Ho ten: ";
	getline(cin, tmp_ngoai_tru[new_so_ngoai_tru - 1].ho_ten);
	cout << "Ngay sinh: ";
	getline(cin, tmp_ngoai_tru[new_so_ngoai_tru - 1].ngay_sinh);
	cout << "Gioi tinh: ";
	getline(cin, tmp_ngoai_tru[new_so_ngoai_tru - 1].gioi_tinh);
	cout << "Chuan doan benh: ";
	getline(cin, tmp_ngoai_tru[new_so_ngoai_tru - 1].chuan_doan_benh);
	cout << "Ngay kham: ";
	getline(cin, tmp_ngoai_tru[new_so_ngoai_tru - 1].ngay_kham);
	cout << "So BHYT: ";
	getline(cin, tmp_ngoai_tru[new_so_ngoai_tru - 1].so_bhyt);
	cout << "Ma tao thuoc: ";
	getline(cin, tmp_ngoai_tru[new_so_ngoai_tru - 1].ma_toa_thuoc);

	delete[] ngoai_tru;
	ngoai_tru = tmp_ngoai_tru;
	so_ngoai_tru = new_so_ngoai_tru;

	cout << "  ***  Them thanh cong  ***\n";
}

// Lop benh_nhan_chuyen_vien quan ly benh nhan chuyen vien
class benh_nhan_chuyen_vien : public benh_nhan{
	protected:
		string ngay_chuyen;
		string noi_chuyen;
	public:
		benh_nhan_chuyen_vien(){}

		// Lay du lieu benh nhan
		string get_ngay_chuyen(){
			return ngay_chuyen;
		}
		string get_noi_chuyen(){
			return noi_chuyen;
		}

		// Sua du lieu benh nhan
		void set_ngay_chuyen(string ngay_chuyen){
			this->ngay_chuyen = ngay_chuyen;
		}
		void set_noi_chuyen(string noi_chuyen){
			this->noi_chuyen = noi_chuyen;
		}

		// Nhap benh nhan chuyen vien tu ban phim
		void nhap(){
			benh_nhan::nhap();
			cout << "Ngay chuyen: ";
			getline(cin, ngay_chuyen);
			cout << "Noi chuyen: ";
			getline(cin, noi_chuyen);
		}
		// Nhap benh nhan chuyen vien tu file
		void file_nhap(){
			benh_nhan::file_nhap();
			getline(file_input, ngay_chuyen);
			getline(file_input, noi_chuyen);
		}
		// Xuat benh nhan chuyen vien ra man hinh
		void xuat(){
			benh_nhan::xuat();
			cout << setw(15) << ngay_chuyen << " |";
			cout << setw(41) << noi_chuyen << " |" << endl;
		}
		// Xuat benh nhan chuyen vien vao file
		void file_xuat(){
			benh_nhan::file_xuat();
			file_output << setw(15) << ngay_chuyen << " |";
			file_output << setw(41) << noi_chuyen << " |" << endl;
		}
		friend void danh_sach_chuyen_vien(benh_nhan_chuyen_vien *chuyen_vien, int so_chuyen_vien);
};
// Danh sach benh nhan chuyen vien ra man hinh
void danh_sach_chuyen_vien(benh_nhan_chuyen_vien *chuyen_vien, int so_chuyen_vien){
	cout << "                                                                   BENH NHAN CHUYEN VIEN\n";
	cout << " _____________________________________________________________________________________________________________________________________________________________________ \n";
	cout << "|    Ma ho so   |       Ho va ten        |  Ngay sinh  | Gioi tinh |           Chuan doan benh            |   Ngay chuyen  |                Noi chuyen                |\n";
	cout << "|---------------|------------------------|-------------|-----------|--------------------------------------|----------------|------------------------------------------|\n";
	for(int i=0; i<so_chuyen_vien; i++){
		chuyen_vien[i].xuat();
	}
	cout << "|_______________|________________________|_____________|___________|______________________________________|________________|__________________________________________|\n";
	cout << endl;
}

int main(){

	// So benh nhan noi tru
	int so_noi_tru;
	file_input >> so_noi_tru;
	file_input.ignore();
	// Tao con tro luu tru du lieu benh nhan noi tru
	benh_nhan_noi_tru *noi_tru = new benh_nhan_noi_tru[so_noi_tru];
	// Doc du lieu benh nhan noi tru
	for(int i=0; i<so_noi_tru; i++){
		noi_tru[i].file_nhap();
	}

	// So benh nhan ngoai tru
	int so_ngoai_tru;
	file_input >> so_ngoai_tru;
	file_input.ignore();
	// Tao con tro luu tru du lieu benh nhan ngoai tru
	benh_nhan_ngoai_tru *ngoai_tru = new benh_nhan_ngoai_tru[so_ngoai_tru];
	// Doc du lieu benh nhan ngoai tru
	for(int i=0; i<so_ngoai_tru; i++){
		ngoai_tru[i].file_nhap();
	}

	// So benh nhan chuyen vien
	int so_chuyen_vien;
	file_input >> so_chuyen_vien;
	file_input.ignore();
	// Tao con tro luu tru du lieu benh nhan chuyen vien
	benh_nhan_chuyen_vien *chuyen_vien = new benh_nhan_chuyen_vien[so_chuyen_vien];
	// Doc du lieu benh nhan chuyen vien
	for(int i=0; i<so_chuyen_vien; i++){
		chuyen_vien[i].file_nhap();
	}

	while(true) {
		cout << "\t\t\t\t               MENU\n";
		cout << "\t\t\t\t1. Xem danh sach benh nhan noi tru.\n";
		cout << "\t\t\t\t2. Xem danh sach benh nhan ngoai tru.\n";
		cout << "\t\t\t\t3. Xem danh sach benh nhan chuyen vien.\n";
		cout << "\t\t\t\t4. Tim kiem benh nhan.\n";
		cout << "\t\t\t\t5. Them benh nhan noi tru.\n";
		cout << "\t\t\t\t6. Them benh nhan ngoai tru.\n";
		cout << "\t\t\t\t7. Chuyen benh nhan noi tru.\n";
		cout << "\t\t\t\t8. Chuyen benh nhan ngoai tru.\n";
		cout << "\t\t\t\t0. Thoat.\n";

		string lua_chon;
		cout << "Nhap lua chon: ";
		getline(cin, lua_chon);

		if(lua_chon == "0"){
			break;
		}
		else if(lua_chon == "1"){
			// Xuất danh sách bệnh nhân nội trú ra màn hình
			danh_sach_noi_tru(noi_tru, so_noi_tru);
		}
		else if(lua_chon == "2"){
			// Xuất danh sách bệnh nhân ngoại trú ra màn hình
			danh_sach_ngoai_tru(ngoai_tru, so_ngoai_tru);
		}
		else if(lua_chon == "3"){
			// Xuất danh sách bệnh nhân chuyển viện ra màn hình
			danh_sach_chuyen_vien(chuyen_vien, so_chuyen_vien);
		}
		else if(lua_chon == "4"){
			string tmp_ma_ho_so;
			cout << "Nhap ma ho so: ";
			getline(cin, tmp_ma_ho_so);

			int check = 0;
			for(int i=0; i<so_noi_tru; i++){
				if(noi_tru[i].get_ma_ho_so() == tmp_ma_ho_so){
					check = 1;
					cout << " _________________________________________________________________ \n";
					cout << "|                                                                 |\n";
					cout << "|                                                                 |\n";
					cout << "|                         HO SO BENH AN                           |\n";
					cout << "|                                                                 |\n";
					cout << "|                                                                 |\n";
					cout << "| Dieu tri noi tru                       " << "Ma ho so: " << left << setw(15) << noi_tru[i].get_ma_ho_so() << "|\n";
					cout << "|                                                                 |\n";
					cout << "| 1. Ho va ten: " << setw(32) << noi_tru[i].get_ho_ten() << "2. Gioi tinh: " << setw(4) << noi_tru[i].get_gioi_tinh() << "|\n";
					cout << "|                                                                 |\n";
					cout << "| 3. Ngay sinh: " << setw(50) << noi_tru[i].get_ngay_sinh() << "|\n";
					cout << "|                                                                 |\n";
					cout << "| 4. Chuan doan benh: " << setw(44) << noi_tru[i].get_chuan_doan_benh() << "|\n";
					cout << "|                                                                 |\n";
					cout << "| 5. Ngay nhap vien: " << setw(45) << noi_tru[i].get_ngay_nhap_vien() << "|\n";
					cout << "|                                                                 |\n";
					cout << "| 6. Ngay ra vien: " << setw(47) << noi_tru[i].get_ngay_ra_vien() << "|\n";
					cout << "|                                                                 |\n";
					cout << "| 7. Ten khoa: " << setw(29) << noi_tru[i].get_ten_khoa() <<  "8. So giuong: " << setw(8) << noi_tru[i].get_so_giuong() << "|\n";
					cout << "|_________________________________________________________________|\n";
					break;
				}
			}
			for(int i=0; i<so_ngoai_tru; i++){
				if(ngoai_tru[i].get_ma_ho_so() == tmp_ma_ho_so){
					check = 1;
					cout << " _________________________________________________________________ \n";
					cout << "|                                                                 |\n";
					cout << "|                                                                 |\n";
					cout << "|                         HO SO BENH AN                           |\n";
					cout << "|                                                                 |\n";
					cout << "|                                                                 |\n";
					cout << "| Dieu tri ngoai tru                     " << "Ma ho so: " << left << setw(15) << ngoai_tru[i].get_ma_ho_so() << "|\n";
					cout << "|                                                                 |\n";
					cout << "| 1. Ho va ten: " << setw(32) << ngoai_tru[i].get_ho_ten() << "2. Gioi tinh: " << setw(4) << ngoai_tru[i].get_gioi_tinh() << "|\n";
					cout << "|                                                                 |\n";
					cout << "| 3. Ngay sinh: " << setw(50) << ngoai_tru[i].get_ngay_sinh() << "|\n";
					cout << "|                                                                 |\n";
					cout << "| 4. Chuan doan benh: " << setw(44) << ngoai_tru[i].get_chuan_doan_benh() << "|\n";
					cout << "|                                                                 |\n";
					cout << "| 5. Ngay kham: " << setw(50) << ngoai_tru[i].get_ngay_kham() << "|\n";
					cout << "|                                                                 |\n";
					cout << "| 6. So BHYT: " << setw(52) << ngoai_tru[i].get_so_bhyt() << "|\n";
					cout << "|                                                                 |\n";
					cout << "| 7. Ma toa thuoc: " << setw(47) << ngoai_tru[i].get_ma_toa_thuoc() << "|\n";
					cout << "|_________________________________________________________________|\n";
					break;
				}
			}
			for(int i=0; i<so_chuyen_vien; i++){
				if(chuyen_vien[i].get_ma_ho_so() == tmp_ma_ho_so){
					check = 1;
					cout << " _________________________________________________________________ \n";
					cout << "|                                                                 |\n";
					cout << "|                                                                 |\n";
					cout << "|                         HO SO BENH AN                           |\n";
					cout << "|                                                                 |\n";
					cout << "|                                                                 |\n";
					cout << "| Benh nhan chuyen vien                  " << "Ma ho so: " << left << setw(15) << chuyen_vien[i].get_ma_ho_so() << "|\n";
					cout << "|                                                                 |\n";
					cout << "| 1. Ho va ten: " << setw(32) << chuyen_vien[i].get_ho_ten() << "2. Gioi tinh: " << setw(4) << chuyen_vien[i].get_gioi_tinh() << "|\n";
					cout << "|                                                                 |\n";
					cout << "| 3. Ngay sinh: " << setw(50) << chuyen_vien[i].get_ngay_sinh() << "|\n";
					cout << "|                                                                 |\n";
					cout << "| 4. Chuan doan benh: " << setw(44) << chuyen_vien[i].get_chuan_doan_benh() << "|\n";
					cout << "|                                                                 |\n";
					cout << "| 5. Ngay chuyen: " << setw(48) << chuyen_vien[i].get_ngay_chuyen() << "|\n";
					cout << "|                                                                 |\n";
					cout << "| 6. Noi chuyen: " << setw(49) << chuyen_vien[i].get_noi_chuyen() << "|\n";
					cout << "|_________________________________________________________________|\n";
					break;
				}
			}
			if(check == 0){
				cout << "Khong tim thay benh nhan.\n";
			}
			cout << right << setw(0);
		}
		else if(lua_chon == "5"){
			them_benh_nhan(noi_tru, so_noi_tru);
		}
		else if(lua_chon == "6"){
			them_benh_nhan(ngoai_tru, so_ngoai_tru);
		}
		else if(lua_chon == "7"){
			// Danh sách bệnh nhân ngoại trú
			danh_sach_noi_tru(noi_tru, so_noi_tru);

			cout << "Xoa benh nhan noi tru:\n";
			string tmp_ma_ho_so;
			cout << "Nhap ma ho so: ";
			getline(cin, tmp_ma_ho_so);

			int check = 0;
			for(int i=0; i<so_noi_tru; i++){
				if(noi_tru[i].get_ma_ho_so() == tmp_ma_ho_so){
					check = 1;

					// Thêm bệnh nhân vào bệnh nhân chuyển viện
					so_chuyen_vien++;
					benh_nhan_chuyen_vien *tmp_chuyen_vien = new benh_nhan_chuyen_vien[so_chuyen_vien];
					for(int j=0; j<so_chuyen_vien-1; j++){
						tmp_chuyen_vien[j] = chuyen_vien[j];
					}
					tmp_chuyen_vien[so_chuyen_vien-1].set_ma_ho_so(noi_tru[i].get_ma_ho_so());
					tmp_chuyen_vien[so_chuyen_vien-1].set_ho_ten(noi_tru[i].get_ho_ten());
					tmp_chuyen_vien[so_chuyen_vien-1].set_ngay_sinh(noi_tru[i].get_ngay_sinh());
					tmp_chuyen_vien[so_chuyen_vien-1].set_gioi_tinh(noi_tru[i].get_gioi_tinh());
					tmp_chuyen_vien[so_chuyen_vien-1].set_chuan_doan_benh(noi_tru[i].get_chuan_doan_benh());
					cout << "Nhap ngay chuyen: ";
					string tmp_ngay_chuyen;
					getline(cin, tmp_ngay_chuyen);
					tmp_chuyen_vien[so_chuyen_vien-1].set_ngay_chuyen(tmp_ngay_chuyen);
					cout << "Nhap noi chuyen: ";
					string tmp_noi_chuyen;
					getline(cin, tmp_noi_chuyen);
					tmp_chuyen_vien[so_chuyen_vien-1].set_noi_chuyen(tmp_noi_chuyen);
					delete[] chuyen_vien;
					chuyen_vien = tmp_chuyen_vien;;

					// Xóa bệnh nhân khỏi bệnh nhân nội trú
					for(int j=i; j<so_noi_tru-1; j++){
						noi_tru[j] = noi_tru[j+1];
					}
					so_noi_tru--;
					benh_nhan_noi_tru *tmp_noi_tru = new benh_nhan_noi_tru[so_noi_tru];
					for(int j=0; j<so_noi_tru; j++){
						tmp_noi_tru[j] = noi_tru[j];
					}
					delete[] noi_tru;
					noi_tru = tmp_noi_tru;
					cout << "  ***   Xoa thanh cong   ***\n";
				}
			}
			if(check == 0){
				cout << "Ma ho so khong dung.\n";
			}
		}
		else if(lua_chon == "8"){
			// Danh sách bệnh nhân ngoại trú
			danh_sach_ngoai_tru(ngoai_tru, so_ngoai_tru);

			cout << "Xoa benh nhan ngoai tru:\n";
			string tmp_ma_ho_so;
			cout << "Nhap ma ho so: ";
			getline(cin, tmp_ma_ho_so);

			int check = 0;

			for(int i=0; i<so_ngoai_tru; i++){
				if(ngoai_tru[i].get_ma_ho_so() == tmp_ma_ho_so){
					check = 1;

					// Thêm bệnh nhân vào bệnh nhân chuyển viện
					so_chuyen_vien++;
					benh_nhan_chuyen_vien *tmp_chuyen_vien = new benh_nhan_chuyen_vien[so_chuyen_vien];
					for(int j=0; j<so_chuyen_vien-1; j++){
						tmp_chuyen_vien[j] = chuyen_vien[j];
					}
					tmp_chuyen_vien[so_chuyen_vien-1].set_ma_ho_so(ngoai_tru[i].get_ma_ho_so());
					tmp_chuyen_vien[so_chuyen_vien-1].set_ho_ten(ngoai_tru[i].get_ho_ten());
					tmp_chuyen_vien[so_chuyen_vien-1].set_ngay_sinh(ngoai_tru[i].get_ngay_sinh());
					tmp_chuyen_vien[so_chuyen_vien-1].set_gioi_tinh(ngoai_tru[i].get_gioi_tinh());
					tmp_chuyen_vien[so_chuyen_vien-1].set_chuan_doan_benh(ngoai_tru[i].get_chuan_doan_benh());
					cout << "Nhap ngay chuyen: ";
					string tmp_ngay_chuyen;
					getline(cin, tmp_ngay_chuyen);
					tmp_chuyen_vien[so_chuyen_vien-1].set_ngay_chuyen(tmp_ngay_chuyen);
					cout << "Nhap noi chuyen: ";
					string tmp_noi_chuyen;
					getline(cin, tmp_noi_chuyen);
					tmp_chuyen_vien[so_chuyen_vien-1].set_noi_chuyen(tmp_noi_chuyen);
					delete[] chuyen_vien;
					chuyen_vien = tmp_chuyen_vien;;

					// Xóa bệnh nhân khỏi bệnh nhân ngoại trú
					for(int j=i; j<so_ngoai_tru-1; j++){
						ngoai_tru[j] = ngoai_tru[j+1];
					}
					so_ngoai_tru--;
					benh_nhan_ngoai_tru *tmp_ngoai_tru = new benh_nhan_ngoai_tru[so_ngoai_tru];
					for(int j=0; j<so_ngoai_tru; j++){
						tmp_ngoai_tru[j] = ngoai_tru[j];
					}
					delete[] ngoai_tru;
					ngoai_tru = tmp_ngoai_tru;
					cout << "  ***   Xoa thanh cong   ***\n";
				}
			}
			if(check == 0){
				cout << "Ma ho so khong dung.\n";
			}
		}
		else{
			cout << "Lua chon khong phu hop.\n";
		}
		system("pause");
		system("cls");
	}

	cout << right;
	// Xuất danh sách bệnh nhân nội trú vào file
	file_output << "                                                             BENH NHAN NOI TRU\n";
	file_output << " _________________________________________________________________________________________________________________________________________________________________________________ \n";
	file_output << "|    Ma ho so   |       Ho va ten        |  Ngay sinh  | Gioi tinh |           Chuan doan benh            | Ngay nhap vien |  Ngay ra vien  |         Ten khoa        | So giuong |\n";
	file_output << "|---------------|------------------------|-------------|-----------|--------------------------------------|----------------|----------------|-------------------------|-----------|\n";
	for(int i=0; i<so_noi_tru; i++){
		noi_tru[i].file_xuat();
	}
	file_output << "|_______________|________________________|_____________|___________|______________________________________|________________|________________|_________________________|___________|\n";
	file_output << endl;

	// Xuất danh sách bệnh nhân ngoại trú vào file
	file_output << "                                                           BENH NHAN NGOAI TRU\n";
	file_output << " _____________________________________________________________________________________________________________________________________________________________ \n";
	file_output << "|    Ma ho so   |       Ho va ten        |  Ngay sinh  | Gioi tinh |           Chuan doan benh            |   Ngay kham    |      So BHYT      | Ma toa thuoc |\n";
	file_output << "|---------------|------------------------|-------------|-----------|--------------------------------------|----------------|-------------------|--------------|\n";
	for(int i=0; i<so_ngoai_tru; i++){
		ngoai_tru[i].file_xuat();
	}
	file_output << "|_______________|________________________|_____________|___________|______________________________________|________________|___________________|______________|\n";
	file_output << endl;

	// Xuất danh sách bệnh nhân chuyển viện vào file
	file_output << "                                                          BENH NHAN CHUYEN VIEN\n";
	file_output << " _____________________________________________________________________________________________________________________________________________________________________ \n";
	file_output << "|    Ma ho so   |       Ho va ten        |  Ngay sinh  | Gioi tinh |           Chuan doan benh            |   Ngay chuyen  |                Noi chuyen                |\n";
	file_output << "|---------------|------------------------|-------------|-----------|--------------------------------------|----------------|------------------------------------------|\n";
	for(int i=0; i<so_chuyen_vien; i++){
		chuyen_vien[i].file_xuat();
	}
	file_output << "|_______________|________________________|_____________|___________|______________________________________|________________|__________________________________________|\n";
	file_output << endl;
	
	// Đóng file
	file_input.close();
	file_input_chuyen_vien.close();
	file_output.close();

	ofstream file_change("du_lieu_vao.txt", ios::out);

	// Lưu thông tin bệnh nhân vào file
	file_change << so_noi_tru << endl;
	for(int i=0; i<so_noi_tru; i++){
		file_change << noi_tru[i].get_ma_ho_so() << endl;
		file_change << noi_tru[i].get_ho_ten() << endl;
		file_change << noi_tru[i].get_ngay_sinh() << endl;
		file_change << noi_tru[i].get_gioi_tinh() << endl;
		file_change << noi_tru[i].get_chuan_doan_benh() << endl;
		file_change << noi_tru[i].get_ngay_nhap_vien() << endl;
		file_change << noi_tru[i].get_ngay_ra_vien() << endl;
		file_change << noi_tru[i].get_ten_khoa() << endl;
		file_change << noi_tru[i].get_so_giuong() << endl;
	}

	file_change << so_ngoai_tru << endl;
	for(int i=0; i<so_ngoai_tru; i++){
		file_change << ngoai_tru[i].get_ma_ho_so() << endl;
		file_change << ngoai_tru[i].get_ho_ten() << endl;
		file_change << ngoai_tru[i].get_ngay_sinh() << endl;
		file_change << ngoai_tru[i].get_gioi_tinh() << endl;
		file_change << ngoai_tru[i].get_chuan_doan_benh() << endl;
		file_change << ngoai_tru[i].get_ngay_kham() << endl;
		file_change << ngoai_tru[i].get_so_bhyt() << endl;
		file_change << ngoai_tru[i].get_ma_toa_thuoc() << endl;
	}

	file_change << so_chuyen_vien << endl;
	for(int i=0; i<so_chuyen_vien; i++){
		file_change << chuyen_vien[i].get_ma_ho_so() << endl;
		file_change << chuyen_vien[i].get_ho_ten() << endl;
		file_change << chuyen_vien[i].get_ngay_sinh() << endl;
		file_change << chuyen_vien[i].get_gioi_tinh() << endl;
		file_change << chuyen_vien[i].get_chuan_doan_benh() << endl;
		file_change << chuyen_vien[i].get_ngay_chuyen() << endl;
		file_change << chuyen_vien[i].get_noi_chuyen() << endl;
	}
	file_change.close();

	return 0;
}