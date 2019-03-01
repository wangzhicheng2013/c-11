a = 10
while (a < 100)
do 
    print ("a = ", a)
    a = a + 1
end
for a = 10, 100
do
    print ("a = ", a)
end
function f(x)
    print ("func")
    return x * 2
end
for i = 1, f(5)
do
    print (i)
end
days = {"1", "2"}
for i, v in ipairs(days)
do
    print (i, v)
end
a = 10
repeat
    print ("a = ", a)
    a = a + 1
    if (a > 20) then
    break
    end
until(a > 100)
