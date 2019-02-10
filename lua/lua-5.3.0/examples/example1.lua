print (type("hello Lua"))
print (type(print))
print (type(AA))
table1 = {key0 = "val0", key1 = "val1"}
print (table1)
for k, v in pairs(table1) do
    print (k .. " - " .. v)
    print (k)
end
A = 1
if A >= 1 then
    print (A)
else
    print ("A")
end
BBB = [[
    CC = a
]]
print (BBB)
rs = "2" + "-0.2"
print (rs)
C = "2" .. "1111A"
print (C)
LL = "ACC123"
print (#LL)
tb = {"A", "B", 123}
print (tb)
for k, v in pairs(tb) do
    print ("key = ", k)
    print ("value = ", v)
end
function Add(a, b)
        return a .. b
end
print (Add(1, 10))
function Fun0(tb, fun)
        for k, v in pairs(tb) do
            print (fun(k, v))
        end
end
tb={ key1 = "1", key2 = "2" }
Fun0(tb, Add)


