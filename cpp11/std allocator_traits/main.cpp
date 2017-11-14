#include <memory>

template <class T, class Alloc>
class MyVector {
	T* data_;
	std::size_t size_;
	Alloc alloc_;
public:
	MyVector(std::size_t size)
	{
		using traits = std::allocator_traits<Alloc>;

		size_ = size;

		// ƒƒ‚ƒŠŠm•Û
		data_ = traits::allocate(alloc_, size);

		// —v‘f‚ğ\’z
		for (std::size_t i = 0; i < size_; ++i) {
			traits::construct(alloc_, &data_[i]);
		}
	}

	~MyVector()
	{
		using traits = std::allocator_traits<Alloc>;

		// —v‘f‚ğ”jŠü
		for (std::size_t i = 0; i < size_; ++i) {
			traits::destroy(alloc_, &data_[i]);
		}

		// ƒƒ‚ƒŠ‚ğ‰ğ•ú
		traits::deallocate(alloc_, data_, size_);
	}
};

int main()
{
	MyVector<int, std::allocator<int>> v(3);

	return 0;
}