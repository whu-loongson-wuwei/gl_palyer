template<typename R,typename... ARGS>
class Function
{
public:
	Function(R(* func)(ARGS...)):_func(func){}
	R operator()(ARGS... args){
		return _func(args...);
	}
private:
	R(* _func)(ARGS...);
};
template<typename R,typename... ARGS>
Function<R,ARGS...>
MakeFunc(R(* _func)(ARGS...)){
	return Function<R,ARGS...>(_func);
}
