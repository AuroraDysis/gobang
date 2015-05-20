#pragma once
#include "stdafx.h"
#include <hash_map>
#include "Line.h"
#include "Boundary.h"

using std::hash_map;
using std::shared_ptr;

class Board
{
public:
	Board(Color _mPieceColor);
	~Board();
	//����
	void input(Axis axis);
	//��������
	void undo_input(Axis axis);
	shared_ptr<Point> operator[](Axis axis);
	//���boundary��Χ�ڿյĵ�
	std::vector<shared_ptr<Point>> empty_points();
	//�ж��Ƿ���һ��ʤ��
	Color judge_win();
	Color turn;
	hash_map<int, shared_ptr<Point>> board;
private:
	Color mPieceColor;
	Color oPieceColor;
	//��������ÿ����ļ�ֵ
	void evaluate_points();
	//��ʼ������
	void initialize();
	shared_ptr<Boundary> boundary;
	
	hash_map<int, shared_ptr<Line>> all_row;
	hash_map<int, shared_ptr<Line>> all_column;
	hash_map<int, shared_ptr<Line>> all_left_oblique;
	hash_map<int, shared_ptr<Line>> all_right_oblique;

	std::vector<shared_ptr<Line>> total_line;
};
