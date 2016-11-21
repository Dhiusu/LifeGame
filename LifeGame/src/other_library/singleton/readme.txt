
/*

mozcのシングルトンクラスはテンプレートを使用することで、どんなクラスでもシングルトン化することができるようになっています。
解放処理は SingletonFinalizer::finalize() を適切なタイミングで呼び出すことで行います。
また、このクラスが必ずシングルトンオブジェクトの生成と逆順でインスタンスの解放を行うことを保証します。

void main() {
    Foo& gFoo = singleton<Foo>::get_instance();
    Bar& gBar = singleton<Bar>::get_instance();
    SingletonFinalizer::finalize();
}

*/
