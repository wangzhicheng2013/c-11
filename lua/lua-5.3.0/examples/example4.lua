if (0)
then 
    print ("0")
end
a = 10
if (a > 10)
then
    print (a)
else
    print ("LL")
end

function Max(num1, num2)
    if (num1 > num2) then
        return num1
    else
        return num2
    end
end
print (Max(1, 100))
myprint = function(param)
    print (param)
end
function Add(x, y, functionPrint)
    z = x + y
    functionPrint(z)
end
Add(10, 100, myprint)
function Sum(...)
    local s = 0
    for i, v in ipairs{...} do
        s = s + v
    end
    return s
end
print (Sum(1, 2, 3))
do
    function foo(...)
        for i = 1, select ('#', ...) do
            local arg = select (i, ...)
            print (arg)
        end
    end
    foo(1, 2, 3)
end
