import sys
from decimal import Decimal
print round(2.9)
print round(10 / 3, 2)
print round(0.5, 2)
print round(0.55, 2)
print round(1.678, 2)
print Decimal('1.22')
print Decimal('0.22')
d = Decimal('6.789')
d.quantize(Decimal('0.00'))
print d
n = Decimal('0.0000416')
n.quantize(Decimal('0.01'))
print n
