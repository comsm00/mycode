import java.awt.*;
import javax.swing.*;
 
public class Pentagon extends JPanel {
    public void paint(Graphics g) {
        g.setColor(Color.YELLOW);
 
        // Pentagon (5 sides)
        int[] px = {150, 230, 200, 100, 70};
        int[] py = {30, 90, 190, 190, 90};
 
        drawDDA(g, px[0], py[0], px[1], py[1]); // Side 1
        drawDDA(g, px[1], py[1], px[2], py[2]); // Side 2
        drawDDA(g, px[2], py[2], px[3], py[3]); // Side 3
        drawDDA(g, px[3], py[3], px[4], py[4]); // Side 4
        drawDDA(g, px[4], py[4], px[0], py[0]); // Side 5
    }
 
    public void drawDDA(Graphics g, int x1, int y1, int x2, int y2) {
        int dx = x2 - x1;
        int dy = y2 - y1;
        int steps = Math.max(Math.abs(dx), Math.abs(dy));
        float xInc = (float) dx / steps;
        float yInc = (float) dy / steps;
        float x = x1;
        float y = y1;
        for (int i = 0; i <= steps; i++) {
            g.fillRect(Math.round(x), Math.round(y), 2, 2);
            x += xInc;
            y += yInc;
        }
    }
 
    public static void main(String[] args) {
        JFrame frame = new JFrame("Pentagon using DDA");
        Pentagon panel = new Pentagon();
        frame.add(panel);
        frame.setSize(350, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
} 


******************************************************************

import javax.swing.*;
import java.awt.*;
 
public class BresenhamAllShapes extends JPanel {
 
    // ---------- Core Bresenham line algorithm ----------
    public void drawBresenhamLine(Graphics g, int x1, int y1, int x2, int y2) {
        int dx = Math.abs(x2 - x1);
        int dy = Math.abs(y2 - y1);
        int sx = (x2 > x1) ? 1 : -1;
        int sy = (y2 > y1) ? 1 : -1;
 
        if (dx >= dy) {
            int d = 2 * dy - dx;
            int y = y1;
            for (int x = x1; x != x2; x += sx) {
                g.fillRect(x, y, 2, 2);
                if (d > 0) { y += sy; d -= 2 * dx; }
                d += 2 * dy;
            }
        } else {
            int d = 2 * dx - dy;
            int x = x1;
            for (int y = y1; y != y2; y += sy) {
                g.fillRect(x, y, 2, 2);
                if (d > 0) { x += sx; d -= 2 * dy; }
                d += 2 * dx;
            }
        }
        g.fillRect(x2, y2, 2, 2);
    }
 
    public void paint(Graphics g) {
        super.paint(g);
 
        // ---------- 1) Yellow Hexagon ----------
        g.setColor(Color.YELLOW.darker());
        drawBresenhamLine(g, 100, 175, 150, 150);
        drawBresenhamLine(g, 150, 150, 200, 175);
        drawBresenhamLine(g, 200, 175, 200, 225);
        drawBresenhamLine(g, 200, 225, 150, 250);
        drawBresenhamLine(g, 150, 250, 100, 225);
        drawBresenhamLine(g, 100, 225, 100, 175);
 
        // ---------- 2) Orange Rectangle ----------
        g.setColor(Color.ORANGE);
        drawBresenhamLine(g, 250, 150, 350, 150);
        drawBresenhamLine(g, 350, 150, 350, 200);
        drawBresenhamLine(g, 350, 200, 250, 200);
        drawBresenhamLine(g, 250, 200, 250, 150);
 
        // ---------- 3) Purple Rhombus / Parallelogram ----------
        g.setColor(new Color(128, 0, 128));
        drawBresenhamLine(g, 400, 200, 430, 150);
        drawBresenhamLine(g, 430, 150, 480, 150);
        drawBresenhamLine(g, 480, 150, 450, 200);
        drawBresenhamLine(g, 450, 200, 400, 200);
 
        // ---------- 4) Blue Pentagon ----------
        g.setColor(Color.BLUE);
        drawBresenhamLine(g, 300, 275, 340, 305);
        drawBresenhamLine(g, 340, 305, 325, 350);
        drawBresenhamLine(g, 325, 350, 275, 350);
        drawBresenhamLine(g, 275, 350, 260, 305);
        drawBresenhamLine(g, 260, 305, 300, 275);
 
        // ---------- 5) Red Triangle ----------
        g.setColor(Color.RED);
        drawBresenhamLine(g, 430, 275, 470, 350);
        drawBresenhamLine(g, 470, 350, 390, 350);
        drawBresenhamLine(g, 390, 350, 430, 275);
 
        // ---------- 6) Green Trapezoid ----------
        g.setColor(new Color(0, 100, 0));
        drawBresenhamLine(g, 120, 300, 200, 300);
        drawBresenhamLine(g, 200, 300, 180, 360);
        drawBresenhamLine(g, 180, 360, 140, 360);
        drawBresenhamLine(g, 140, 360, 120, 300);
 
        // ---------- 7) Black Hexagon with internal triangulation ----------
        g.setColor(Color.BLACK);
        drawBresenhamLine(g, 500, 250, 700, 400);
        drawBresenhamLine(g, 700, 400, 300, 400);
        drawBresenhamLine(g, 700, 400, 700, 550);
        drawBresenhamLine(g, 700, 550, 500, 700);
        drawBresenhamLine(g, 700, 550, 300, 550);
        drawBresenhamLine(g, 700, 550, 500, 250);
        drawBresenhamLine(g, 500, 700, 500, 550);
        drawBresenhamLine(g, 500, 700, 300, 550);
        drawBresenhamLine(g, 500, 550, 400, 400);
        drawBresenhamLine(g, 500, 550, 600, 400);
        drawBresenhamLine(g, 300, 550, 300, 400);
        drawBresenhamLine(g, 300, 550, 500, 250);
        drawBresenhamLine(g, 300, 400, 500, 250);
    }
 
    public static void main(String[] args) {
        JFrame frame = new JFrame("Bresenham Line Drawing - All Shapes");
        BresenhamAllShapes panel = new BresenhamAllShapes();
        panel.setBackground(Color.WHITE);
        frame.add(panel);
        frame.setSize(900, 800);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
 ************************************************************************

 import java.awt.*;
import javax.swing.*;
public class Pentagon extends JPanel {
    public void paint(Graphics g) {
        g.setColor(Color.RED);

        // Pentagon (5 sides)
        drawDDA(g, 200, 50, 350, 50);   // Side 1
       drawDDA(g, 350, 50, 350, 100);  // Side 2
        drawDDA(g, 200, 100, 350, 100);  // Side 3
        drawDDA(g, 200, 50, 200, 100);  // Side 4
        drawDDA(g, 200, 50, 200, 500);   // Side 5
    }
    public void drawDDA(Graphics g, int x1, int y1, int x2, int y2) {
        int dx = x2 - x1;
        int dy = y2 - y1;
        int steps = Math.max(Math.abs(dx), Math.abs(dy));
        float xInc = (float) dx / steps;
        float yInc = (float) dy / steps;
        float x = x1;
        float y = y1;
        for (int i = 0; i <= steps; i++) {
            g.fillRect(Math.round(x), Math.round(y), 2, 2);
            x += xInc;
            y += yInc;
        }
    }
    public static void main(String[] args) {
        JFrame frame = new JFrame("Pentagon using DDA");
        Pentagon panel = new Pentagon();
        frame.add(panel);
        frame.setSize(450, 350);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
