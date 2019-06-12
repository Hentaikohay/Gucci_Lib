#pragma once
#include<iterator>
namespace my_space 
{
	/*константные итераторы по ключам для 
		*	Vertex	*
		*	Edge	*/
	
	template <typename C>
	class VertexIterator : public std::iterator<std::forward_iterator_tag, const typename C::key_type >
	{
	public:

		using key_type			=	typename C::key_type;
		using const_iterator	=	typename C::const_iterator;

		VertexIterator(const_iterator it_)
			: m_it (it_)
		{
		}

		const key_type operator *()
		{
			return m_it->first;
		}

		VertexIterator& operator ++()
		{
			++m_it;
			return *this;
		}

		VertexIterator  operator ++(int)
		{
			VertexIterator tmp(m_it);
			++m_it;
			return tmp;
		}

		bool operator !=(const VertexIterator& itr_)
		{
			return m_it != itr_.m_it;
		}

	private:
		const_iterator m_it;
	};

	template <typename C>
	class EdgeIterator : public std::iterator<std::forward_iterator_tag, const typename C::key_type >
	{
	public:

		using key_type			= typename C::key_type;
		using const_iterator	= typename C::const_iterator;

		EdgeIterator(const_iterator it_)
			: m_it(it_)
		{
		}

		const key_type operator *()
		{
			return m_it->first;
		}

		bool operator !=(const EdgeIterator& itr_)
		{
			return m_it != itr_.m_it;
		}

		EdgeIterator& operator ++()
		{
			++m_it;
			return *this;
		}

		EdgeIterator operator ++(int)
		{
			EdgeIterator tmp(m_it);
			++m_it;
			return tmp;
		}
	private:
		const_iterator m_it;
	};

	/*Обертка для итераторов выше */
	template <typename Container>
	class Vertices
	{
	public:
		using const_iterator = VertexIterator< Container >;

		Vertices(const Container& container_) : m_contaiter(container_)
		{
		}

		const_iterator begin() const
		{
			return const_iterator(m_contaiter.begin());
		}
		
		const_iterator end() const 
		{
			return const_iterator(m_contaiter.end());
		}
		
	private:
		const Container& m_contaiter;

	};

	template <typename Container>
	class Edges
	{
	public:
		using const_iterator = EdgeIterator< Container >;

		Edges(const Container& container_) : m_contaiter(container_)
		{
		}

		const_iterator begin() const
		{
			return const_iterator(m_contaiter.begin());
		}

		const_iterator end() const
		{
			return const_iterator(m_contaiter.end());
		}

	private:
		const Container& m_contaiter;
	};

	class Nears
	{
	public:

		using vector_itr = std::vector<int>::const_iterator;

		Nears(vector_itr begin_, vector_itr end_)
			: m_begin(begin_), m_end(end_)
		{
		}

		vector_itr begin() { return m_begin; }
		vector_itr end() { return m_end; }

	private:

		vector_itr m_begin;
		vector_itr m_end;

	};

}
