#pragma once
#include<map>
#include<vector>
#include<cstddef>
#include"iterators.h"
namespace my_space
{
	struct NoProperty {};
	
	struct EdgeDescriptor
	{
		friend bool operator <(const EdgeDescriptor lft_, const EdgeDescriptor rht_) {
			if (lft_.source == rht_.source)
				return lft_.target < rht_.target;
			else
				return lft_.source < rht_.source;
		}
		int source;	
		int target;
	};

	template<	class VertexProperty = NoProperty,
				class EdgeProperty = NoProperty,
				class GraphProperty = NoProperty
			>
	class Graph
	{
	public:

		using VertexDescriptor  = int;
		using VertexMap			= std::map<VertexDescriptor, VertexProperty>;

		using EdgeMap			= std::map<EdgeDescriptor, EdgeProperty>;
		using Vector			= std::vector<VertexDescriptor>;				
		using NearList			= std::map<VertexDescriptor, Vector>;

		VertexDescriptor addVertex()
		{
			VertexDescriptor descr = sizeVertices();
			m_nearList[descr];

			return descr;
		}
		VertexDescriptor addVertex(const VertexProperty& property_)
		{
			VertexDescriptor descr = addVertex();
			m_setVertices[descr] = property_;

			return descr;
		}

		EdgeDescriptor addEdge (const VertexDescriptor source_, const VertexDescriptor target_)
		{
			m_nearList[source_].push_back(target_);

			EdgeDescriptor descr;
			descr.source = source_;
			descr.target = target_;

			m_setEdges[descr];

			return descr;
		}
		
		EdgeDescriptor addEdge
			(const VertexDescriptor source_, const VertexDescriptor target_, const EdgeProperty property_)
		{
			EdgeDescriptor descr = addEdge(source_, target_);
			m_setEdges[descr] = property_;

			return descr;
		}

		VertexProperty& operator [](const VertexDescriptor vertex_)
		{
			return m_setVertices[vertex_];
		}
		const VertexProperty& operator [](const VertexDescriptor vertex_) const
		{ 
			return m_setVertices[vertex_]; 
		}

		VertexProperty& at(const VertexDescriptor vertex_)
		{
			return m_setVertices.at(vertex_);
		}
		const VertexProperty& at(const VertexDescriptor vertex_) const
		{
			return m_setVertices.at(vertex_);
		}

		EdgeProperty& operator [] (const EdgeDescriptor& edge_)
		{
			return m_setEdges.at(edge_);
		}
		const EdgeProperty& operator [] (const EdgeDescriptor& edge_) const
		{
			return m_setEdges.at(edge_);
		}

		const GraphProperty& getGraphProperty() const { return m_graphProperty; }

		void setGraphProperty(const GraphProperty& property_) { m_graphProperty = property_; }

		size_t sizeVertices()const { return m_setVertices.size(); }
		size_t sizeEdges() const { return m_setEdges.size(); }

		using vertex_iterator	= Vertices	<VertexMap>;
		using edge_iterator		= Edges		<EdgeMap>;

		vertex_iterator vertices() const
		{
			return vertex_iterator(m_setVertices);
		}
		edge_iterator edges() const
		{
			return edge_iterator(m_setEdges);
		}

		Nears nearList(const VertexDescriptor vertex_) const
		{
			return Nears(m_nearList.at(vertex_).begin(),
						 m_nearList.at(vertex_).end());
		}

	
	private:
		NearList m_nearList;	// список смежностей

		EdgeMap m_setEdges;	// пары вершин -> свойство ребра

		VertexMap m_setVertices;

		GraphProperty m_graphProperty;
	};

	
	
}
