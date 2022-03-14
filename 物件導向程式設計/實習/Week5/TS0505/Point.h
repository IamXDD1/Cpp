class Point {
	float pos[2];
public:
	Point();
	~Point();
	void Set(float x, float y);
	void Move(float x, float y);
	void Rotate();
	void Reflect();
	float GetHorizontal();
	float GetVertical();
};