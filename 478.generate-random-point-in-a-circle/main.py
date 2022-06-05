import random
import math

class Solution(object):

    def __init__(self, radius, x_center, y_center):
        """
        :type radius: float
        :type x_center: float
        :type y_center: float
        """
        self.radius = radius
        self.x = x_center
        self.y = y_center


    def randPoint(self):
        """
        :rtype: List[float]
        """
        r = math.sqrt(random.random())
        theta = random.random() * 2 * math.pi
        return [r * math.cos(theta) * self.radius + self.x, r * math.sin(theta) * self.radius + self.y]
