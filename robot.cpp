#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include <FL/gl.h>

#include "modelerglobals.h"

enum RobotCtrls {
	X, Y, Z, 
	BODYHEIGHT, BODYWIDTH, NECKHEIGHT, HEADSCALE, 
	LEFTARM1X, LEFTARM1Y, LEFTARM1Z, LEFTARM2X, LEFTARM2Y, LEFTARM2Z,
	RIGHTARM1X, RIGHTARM1Y, RIGHTARM1Z, RIGHTARM2X, RIGHTARM2Y, RIGHTARM2Z,
	LEFTLEGX, LEFTLEGY, LEFTLEGZ, 
	RIGHTLEGX, RIGHTLEGY, RIGHTLEGZ,
	BOTHLEGSX, BOTHLEGSY, BOTHLEGSZ,
	TOTAL
};

static GLfloat lightPosition2[] = { -20, -20, -20, 0 };
static GLfloat lightDiffuse2[] = { 1,1,1,0.5 };
static GLfloat lightAmbient2[] = { 0.2f, 0.2f, 0.2f, 1.0f };
static GLint angleInc = 0;

class Robot : public ModelerView {
public:
	Robot(int x, int y, int w, int h, char* label) 
		: ModelerView(x, y, w, h, label) {}

	virtual void draw();
};

ModelerView* createRobot(int x, int y, int w, int h, char* label) {
	return new Robot(x, y, w, h, label);
}

void Robot::draw()
{
	ModelerView::draw();

	glEnable(GL_LIGHT2);

	glLightfv(GL_LIGHT2, GL_POSITION, lightPosition2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, lightDiffuse2);
	glLightfv(GL_LIGHT2, GL_AMBIENT, lightAmbient2);

	
	if (angleInc == 360) {
		angleInc = 0;
	}
	else {
		angleInc += 3;
	}

	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_GREEN);

	glPushMatrix();
		glTranslated(VAL(X), VAL(Y), VAL(Z));

		glPushMatrix();
		glTranslated(0, 1, 0);
		glRotated(90, 1, 0, 0);
		drawCylinder(VAL(BODYHEIGHT), VAL(BODYWIDTH), VAL(BODYWIDTH));
			
			setAmbientColor(.1f, .1f, .1f);
			setDiffuseColor(COLOR_RED);
			glPushMatrix();
			glTranslated(VAL(BODYWIDTH), 0, 0.2 * VAL(BODYHEIGHT));
			drawSphere(0.075 * VAL(BODYHEIGHT));

			setAmbientColor(.1f, .1f, .1f);
			setDiffuseColor(COLOR_BLUE);
			glRotated(30, 0, 1, 0);
			glRotated(VAL(LEFTARM1X), 1, 0, 0);
			glRotated(VAL(LEFTARM1Y), 0, 1, 0);
			glRotated(VAL(LEFTARM1Z), 0, 0, 1);
			drawCylinder(0.4 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT));

				glPushMatrix();
				glTranslated(0, 0, 0.4 * VAL(BODYHEIGHT));
				setAmbientColor(.1f, .1f, .1f);
				setDiffuseColor(COLOR_RED);
				drawSphere(0.075 * VAL(BODYHEIGHT));

				setAmbientColor(.1f, .1f, .1f);
				setDiffuseColor(COLOR_BLUE);
				glRotated(-30, 0, 1, 0);
				glRotated(VAL(LEFTARM2X), 1, 0, 0);
				glRotated(VAL(LEFTARM2Y), 0, 1, 0);
				glRotated(VAL(LEFTARM2Z), 0, 0, 1);
				drawCylinder(0.4 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT));

					glPushMatrix();
					glTranslated(0, 0.06 * VAL(BODYHEIGHT), 0.4 * VAL(BODYHEIGHT));
	
					setAmbientColor(.1f, .1f, .1f);
					setDiffuseColor(COLOR_GREEN);
					glRotated(90, 1, 0, 0);
					drawCylinder(0.12 * VAL(BODYHEIGHT), 0.09 * VAL(BODYHEIGHT), 0.09 * VAL(BODYHEIGHT));

					glPopMatrix();

				glPopMatrix();

			glPopMatrix();

			setAmbientColor(.1f, .1f, .1f);
			setDiffuseColor(COLOR_RED);
			glPushMatrix();
			glTranslated(-VAL(BODYWIDTH), 0, 0.2 * VAL(BODYHEIGHT));
			drawSphere(0.075 * VAL(BODYHEIGHT));

			setAmbientColor(.1f, .1f, .1f);
			setDiffuseColor(COLOR_BLUE);
			glRotated(-30, 0, 1, 0);
			glRotated(VAL(RIGHTARM1X), 1, 0, 0);
			glRotated(VAL(RIGHTARM1Y), 0, 1, 0);
			glRotated(VAL(RIGHTARM1Z), 0, 0, 1);
			drawCylinder(0.4 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT));

				glPushMatrix();
				glTranslated(0, 0, 0.4 * VAL(BODYHEIGHT));
				setAmbientColor(.1f, .1f, .1f);
				setDiffuseColor(COLOR_RED);
				drawSphere(0.075 * VAL(BODYHEIGHT));

				setAmbientColor(.1f, .1f, .1f);
				setDiffuseColor(COLOR_BLUE);
				glRotated(30, 0, 1, 0);
				glRotated(VAL(RIGHTARM2X), 1, 0, 0);
				glRotated(VAL(RIGHTARM2Y), 0, 1, 0);
				glRotated(VAL(RIGHTARM2Z), 0, 0, 1);
				drawCylinder(0.4 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT));

					glPushMatrix();
					glTranslated(0, 0.06 * VAL(BODYHEIGHT), 0.4 * VAL(BODYHEIGHT));

					setAmbientColor(.1f, .1f, .1f);
					setDiffuseColor(COLOR_GREEN);
					glRotated(90, 1, 0, 0);
					drawCylinder(0.12 * VAL(BODYHEIGHT), 0.09 * VAL(BODYHEIGHT), 0.09 * VAL(BODYHEIGHT));

					glPopMatrix();

				glPopMatrix();

			glPopMatrix();

			glPushMatrix();
			glRotated(180, 1, 0, 0);
			drawCylinder(VAL(NECKHEIGHT), 0.2 * VAL(BODYWIDTH), 0.2 * VAL(BODYWIDTH));

				glPushMatrix();
				glTranslated(-VAL(HEADSCALE) /2.0, -VAL(HEADSCALE) / 4.0, VAL(NECKHEIGHT));
				glScaled(VAL(HEADSCALE), VAL(HEADSCALE)/2.0, VAL(HEADSCALE)/2.0);
				drawBox(1, 1, 1);
				glPopMatrix();

			glPopMatrix();

			glPushMatrix();
			glTranslated(VAL(BODYWIDTH)/2.0, 0, VAL(BODYHEIGHT));

			setAmbientColor(.1f, .1f, .1f);
			setDiffuseColor(COLOR_RED);
			drawSphere(0.075 * VAL(BODYHEIGHT));

			setAmbientColor(.1f, .1f, .1f);
			setDiffuseColor(COLOR_BLUE);
			glRotated(VAL(LEFTLEGX) + VAL(BOTHLEGSX), 1, 0, 0);
			glRotated(VAL(LEFTLEGY) + VAL(BOTHLEGSY), 0, 1, 0);
			glRotated(VAL(LEFTLEGZ) + VAL(BOTHLEGSZ), 0, 0, 1);
			drawCylinder(0.4 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT));

				glPushMatrix();
				glTranslated(-0.1 * VAL(BODYHEIGHT), -0.1 * VAL(BODYHEIGHT), 0.4 * VAL(BODYHEIGHT));
				setAmbientColor(.1f, .1f, .1f);
				setDiffuseColor(COLOR_GREEN);
				drawBox(0.2 * VAL(BODYHEIGHT), 0.2 * VAL(BODYHEIGHT), 0.075 * VAL(BODYHEIGHT));
				glPopMatrix();
			
			glPopMatrix();

			glPushMatrix();
			glTranslated(-VAL(BODYWIDTH) / 2.0, 0, VAL(BODYHEIGHT));

			setAmbientColor(.1f, .1f, .1f);
			setDiffuseColor(COLOR_RED);
			drawSphere(0.075 * VAL(BODYHEIGHT));

			setAmbientColor(.1f, .1f, .1f);
			setDiffuseColor(COLOR_BLUE);
			glRotated(VAL(RIGHTLEGX) + VAL(BOTHLEGSX), 1, 0, 0);
			glRotated(VAL(RIGHTLEGY) + VAL(BOTHLEGSY), 0, 1, 0);
			glRotated(VAL(RIGHTLEGZ) + VAL(BOTHLEGSZ), 0, 0, 1);
			drawCylinder(0.4 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT));

				glPushMatrix();
				glTranslated(-0.1 * VAL(BODYHEIGHT), -0.1 * VAL(BODYHEIGHT), 0.4 * VAL(BODYHEIGHT));
				setAmbientColor(.1f, .1f, .1f);
				setDiffuseColor(COLOR_GREEN);
				drawBox(0.2 * VAL(BODYHEIGHT), 0.2 * VAL(BODYHEIGHT), 0.075 * VAL(BODYHEIGHT));
				glPopMatrix();

			glPopMatrix();

		glPopMatrix();

	glPopMatrix();
}

int main() {
	ModelerControl controls[TOTAL];
	controls[X] = ModelerControl("X Position", -5, 5, 1, 0);
	controls[Y] = ModelerControl("Y Position", -5, 5, 1, 0);
	controls[Z] = ModelerControl("Z Position", -5, 5, 1, 0);
	controls[BODYHEIGHT] = ModelerControl("Body Height", 1.5f, 4.5f, 0.1f, 3.0f);
	controls[BODYWIDTH] = ModelerControl("Body Width", 1.0f, 2.0f, 0.1f, 1.3f);
	controls[NECKHEIGHT] = ModelerControl("Neck Height", 0.1f, 0.5f, 0.1f, 0.3f);
	controls[HEADSCALE] = ModelerControl("Head Scale", 1.5f, 3.0f, 0.1f, 2.0f);
	controls[LEFTARM1X] = ModelerControl("Left Arm 1 X", -180, 180, 1, 0);
	controls[LEFTARM1Y] = ModelerControl("Left Arm 1 Y", -180, 180, 1, 0);
	controls[LEFTARM1Z] = ModelerControl("Left Arm 1 Z", -180, 180, 1, 0);
	controls[LEFTARM2X] = ModelerControl("Left Arm 2 X", -180, 180, 1, 0);
	controls[LEFTARM2Y] = ModelerControl("Left Arm 2 Y", -180, 180, 1, 0);
	controls[LEFTARM2Z] = ModelerControl("Left Arm 2 Z", -180, 180, 1, 0);
	controls[RIGHTARM1X] = ModelerControl("Right Arm 1 X", -180, 180, 1, 0);
	controls[RIGHTARM1Y] = ModelerControl("Right Arm 1 Y", -180, 180, 1, 0);
	controls[RIGHTARM1Z] = ModelerControl("Right Arm 1 Z", -180, 180, 1, 0);
	controls[RIGHTARM2X] = ModelerControl("Right Arm 2 X", -180, 180, 1, 0);
	controls[RIGHTARM2Y] = ModelerControl("Right Arm 2 Y", -180, 180, 1, 0);
	controls[RIGHTARM2Z] = ModelerControl("Right Arm 2 Z", -180, 180, 1, 0);
	controls[LEFTLEGX] = ModelerControl("Left Leg X", -180, 180, 1, 0);
	controls[LEFTLEGY] = ModelerControl("Left Leg Y", -180, 180, 1, 0);
	controls[LEFTLEGZ] = ModelerControl("Left Leg Z", -180, 180, 1, 0);
	controls[RIGHTLEGX] = ModelerControl("Right Leg X", -180, 180, 1, 0);
	controls[RIGHTLEGY] = ModelerControl("Right Leg Y", -180, 180, 1, 0);
	controls[RIGHTLEGZ] = ModelerControl("Right Leg Z", -180, 180, 1, 0);
	controls[BOTHLEGSX] = ModelerControl("Both Legs X", -180, 180, 1, 0);
	controls[BOTHLEGSY] = ModelerControl("Both Legs Y", -180, 180, 1, 0);
	controls[BOTHLEGSZ] = ModelerControl("Both Legs Z", -180, 180, 1, 0);
	

	ModelerApplication::Instance()->Init(&createRobot, controls, TOTAL);
	return ModelerApplication::Instance()->Run();
}