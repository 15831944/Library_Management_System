#include "stdafx.h"
#include"video_model.h"
video_model::video_model(
	long long id,
	string title,
	string author,
	int classification,  //����
	bool E_Resourse,
	string producer,
	string production_time,
	int duration
	):media_data_base(id,media_data_base::VIDEO,title,author,classification,E_Resourse){
	this->producer = producer;
	this->production_time = producer;
	this->duration = duration;
}


//������
string video_model::toString(){
	return "";
}


//������
bool video_model::checkData(){
	return true;
}