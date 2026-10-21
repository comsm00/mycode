import javax.swing.*;
import java.awt.*;

public class HouseTransformation extends JPanel {

    // DDA Line Drawing Algorithm
    public void dda(Graphics g, int x0, int y0,
                    int x1, int y1) {

        int dx = x1 - x0;
        int dy = y1 - y0;

        int steps = Math.max(Math.abs(dx), Math.abs(dy));

        if (steps == 0) {
            g.fillRect(x0, y0, 1, 1);
            return;
        }

        float xInc = (float) dx / steps;
        float yInc = (float) dy / steps;

        float x = x0;
        float y = y0;

        for (int i = 0; i <= steps; i++) {
            g.fillRect(Math.round(x), Math.round(y), 1, 1);
            x += xInc;
            y += yInc;
        }
    }

    // Translation
    public void translate(int[][] xy, int tx, int ty) {

        for (int i = 0; i < xy.length; i++) {
            xy[i][0] += tx;
            xy[i][1] += ty;
        }
    }

    // Scaling
    public void scale(int[][] xy, double sx, double sy) {

        for (int i = 0; i < xy.length; i++) {
            xy[i][0] = (int) Math.round(xy[i][0] * sx);
            xy[i][1] = (int) Math.round(xy[i][1] * sy);
        }
    }

    // Rotation
    public void rotate(int[][] xy, double angle) {

        double rad = Math.toRadians(angle);

        for (int i = 0; i < xy.length; i++) {

            int x = xy[i][0];
            int y = xy[i][1];

            xy[i][0] = (int) Math.round(
                x * Math.cos(rad) - y * Math.sin(rad));

            xy[i][1] = (int) Math.round(
                x * Math.sin(rad) + y * Math.cos(rad));
        }
    }

    // Draw Lines using DDA
    public void drawLines(Graphics g, int[][] xy) {

        for (int i = 0; i < xy.length - 1; i++) {

            dda(g, xy[i][0], xy[i][1],
                   xy[i + 1][0], xy[i + 1][1]);
        }
    }

    // Copy Coordinates
    public int[][] copyPoints(int[][] xy) {

        int[][] copy = new int[xy.length][2];

        for (int i = 0; i < xy.length; i++) {
            copy[i][0] = xy[i][0];
            copy[i][1] = xy[i][1];
        }

        return copy;
    }

    // Transform and Draw One House
    public void drawHouse(Graphics g,
                          int[][] body,
                          int[][] roof,
                          int[][] door,
                          int angle,
                          int tx, int ty,
                          Color color) {

        int[][] b = copyPoints(body);
        int[][] r = copyPoints(roof);
        int[][] d = copyPoints(door);

        // Scale 0.6
        scale(b, 0.6, 0.6);
        scale(r, 0.6, 0.6);
        scale(d, 0.6, 0.6);

        // Rotation
        rotate(b, angle);
        rotate(r, angle);
        rotate(d, angle);

        // Translation
        translate(b, tx, ty);
        translate(r, tx, ty);
        translate(d, tx, ty);

        // Draw House
        g.setColor(color);

        drawLines(g, b);
        drawLines(g, r);
        drawLines(g, d);
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        // Original House Coordinates (Given)

        // Body
        int[][] body = {
            {-100, 100},
            {100, 100},
            {100, 300},
            {-100, 300},
            {-100, 100}
        };

        // Roof
        int[][] roof = {
            {-100, 100},
            {0, 0},
            {100, 100},
            {-100, 100}
        };

        // Door
        int[][] door = {
            {-30, 300},
            {30, 300},
            {30, 220},
            {-30, 220},
            {-30, 300}
        };

        // Top House - 0 Degree
        drawHouse(g, body, roof, door,
                  0, 400, 40, Color.RED);

        // Right House - 90 Degree Clockwise
        drawHouse(g, body, roof, door,
                  90, 650, 350, Color.GREEN);

        // Bottom House - 180 Degree
        drawHouse(g, body, roof, door,
                  180, 400, 650, Color.ORANGE);

        // Left House - 270 Degree Clockwise
        drawHouse(g, body, roof, door,
                  270, 150, 350, Color.MAGENTA);
    }

    public static void main(String[] args) {

        JFrame frame =
            new JFrame("House Transformation");

        frame.add(new HouseTransformation());

        frame.setSize(800, 740);

        frame.setDefaultCloseOperation(
            JFrame.EXIT_ON_CLOSE);

        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
 }


 ******-------******-----****-----******-----***

 
 public void dda(Graphics g, int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    
    // Find the number of steps required
    int steps = Math.max(Math.abs(dx), Math.abs(dy));
    
    // Calculate increment in x and y for each step
    float xInc = dx / (float) steps;
    float yInc = dy / (float) steps;
    
    float x = x0;
    float y = y0;
    
    for (int i = 0; i <= steps; i++) {
        // Draw the pixel (using a small rectangle or fillRect)
        g.fillRect(Math.round(x), Math.round(y), 1, 1);
        x += xInc;
        y += yInc;
    }
 }

 .........................
 
 public void BreCir(Graphics g, int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int p = 1 - r; // Initial decision parameter

    drawSymmetricPoints(g, xc, yc, x, y);

    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
        drawSymmetricPoints(g, xc, yc, x, y);
    }
}

// Helper method to plot points in all 8 octants
private void drawSymmetricPoints(Graphics g, int xc, int yc, int x, int y) {
    g.fillRect(xc + x, yc + y, 1, 1);
    g.fillRect(xc - x, yc + y, 1, 1);
    g.fillRect(xc + x, yc - y, 1, 1);
    g.fillRect(xc - x, yc - y, 1, 1);
    g.fillRect(xc + y, yc + x, 1, 1);
    g.fillRect(xc - y, yc + x, 1, 1);
    g.fillRect(xc + y, yc - x, 1, 1);
    g.fillRect(xc - y, yc - x, 1, 1);
 }

 .......................

 public void translate(int[][] xy, int tx, int ty) {
    // xy is a 2D array where each row represents a point/vertex [x, y]
    for (int i = 0; i < xy.length; i++) {
        xy[i][0] += tx; // Translate x coordinate
        xy[i][1] += ty; // Translate y coordinate
    }
 }
......................
public void scale(int[][] xy, int sx, int sy) {
    // Multiplying each vertex coordinate (x, y) by scaling factors sx and sy
    for (int i = 0; i < xy.length; i++) {
        xy[i][0] = (int) Math.round(xy[i][0] * sx);
        xy[i][1] = (int) Math.round(xy[i][1] * sy);
    }
 }
.....................
 public void rotate(int[][] xy, double angle) {
    // Convert angle from degrees to radians
    double radians = Math.toRadians(angle);
    double cos = Math.cos(radians);
    double sin = Math.sin(radians);

    for (int i = 0; i < xy.length; i++) {
        double x = xy[i][0];
        double y = xy[i][1];
        
        // Rotation about the origin formulas:
        // x' = x * cos(theta) - y * sin(theta)
        // y' = x * sin(theta) + y * cos(theta)
        xy[i][0] = (int) Math.round(x * cos - y * sin);
        xy[i][1] = (int) Math.round(x * sin + y * cos);
    }
 }
.........................
 public void rotate(Graphics g, float a[][2], int n, int x_pivot, int y_pivot, int angle)[span_5](start_span)[span_5](end_span) {
    double rad = Math.toRadians(angle);
    double cos = Math.cos(rad);
    double sin = Math.sin(rad);
    
    int[] rotX = new int[n];
    int[] rotY = new int[n];
    
    for (int i = 0; i < n; i++) {
        float x = a[i][0];
        float y = a[i][1];
        
        // Translate to origin, rotate, then translate back
        double x_prime = x_pivot + (x - x_pivot) * cos - (y - y_pivot) * sin;
        double y_prime = y_pivot + (x - x_pivot) * sin + (y - y_pivot) * cos;
        
        rotX[i] = (int) Math.round(x_prime);
        rotY[i] = (int) Math.round(y_prime);
    }
    
    g.drawPolygon(rotX, rotY, n);
 }
 
 
