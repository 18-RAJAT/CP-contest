#include <map>
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
        if(!(keyBegin<keyEnd)) {
            return;
        }
        auto itBegin=m_map.upper_bound(keyBegin);
        auto itEnd=m_map.upper_bound(keyEnd);
        if(itBegin==m_map.begin()) {
            m_map[keyBegin]=val;
        } else {
            auto it=itBegin;
            --it;
            if(it->second==val) {
                itBegin=it;
            } else {
                m_map[keyBegin]=val;
            }
        }
        if(itEnd==m_map.begin()) {
            m_map[keyEnd]=m_valBegin;
        } else {
            auto it=itEnd;
            --it;
            if(it->second==val) {
                itEnd=it;
            } else {
                m_map[keyEnd]=it->second;
            }
        }
        m_map.erase(++itBegin,itEnd);
	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};
