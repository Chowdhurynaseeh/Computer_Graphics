void Draw_pointer(float cx, float cy, float r, int num_segments)
{
    /// ------------------------------Function For Displaying Pointer on Game Display ---------------------------

	float theta = 2 * 3.1415926 / float(num_segments);
	float tangetial_factor = tanf(theta);
	float radial_factor = cosf(theta);
	float x = r;
	float y = 0;
	glLineWidth(3);

	glBegin(GL_LINE_LOOP);
	glColor3f(1, 0, 0);

	for (int i = 0; i < num_segments; i++)
	{
		glVertex2f(x + cx, y + cy);
		float tx = -y;
		float ty = x;

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;


		x *= radial_factor;
		y *= radial_factor;
	}
	glEnd();
}
void Second_Draw_Pointer(float cx, float cy, float r, int num_segments)
{
    /// ------------------------------Function For Displaying Pointer on Game Display ---------------------------

	float theta = 2 * 3.1415926 / float(num_segments);
	float tangetial_factor = tanf(theta);
	float radial_factor = cosf(theta);
	float x = r;
	float y = 0;
	glLineWidth(3);

	glBegin(GL_LINE_LOOP);
	glColor3f(1, 0, 0);

	for (int i = 0; i < num_segments; i++)
	{
		glVertex2f(x + cx, y + cy);
		float tx = -y;
		float ty = x;

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;


		x *= radial_factor;
		y *= radial_factor;
	}
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex2f(0, -r-3);
	glVertex2f(0, -4);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex2f(0, r+3);
	glVertex2f(0, 4);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex2f(-r-3, 0);
	glVertex2f(-4, 0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex2f(r+3, 0);
	glVertex2f(4, 0);
	glEnd();
}
