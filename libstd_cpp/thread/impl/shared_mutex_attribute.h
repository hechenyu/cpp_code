// -*- C++ -*-
// HeXu's
// 2014 Jan

#ifndef HX_SHARED_MUTEX_ATTRIBUTE_H
#define HX_SHARED_MUTEX_ATTRIBUTE_H

#include <cassert>
#include <pthread.h>
#include "system_error.h"
#include "key_words.h"

namespace Hx {

class shared_mutex_attribute {
private:
	pthread_rwlockattr_t attr_;

public:
	typedef	pthread_rwlockattr_t *native_handle_type;
	typedef	const pthread_rwlockattr_t *const_native_handle_type;

	explicit shared_mutex_attribute()
	{
		int err = pthread_rwlockattr_init(&attr_);
		if (err != 0) {
			throw system_error(err, system_category(), __func__);
		}
	}

	~shared_mutex_attribute()
	{
		int err = pthread_rwlockattr_destroy(&attr_);
		(void) err;
		assert(err == 0);
	}

#if __cplusplus >= 201103L
	shared_mutex_attribute(const shared_mutex_attribute &) = delete;
	shared_mutex_attribute &operator =(const shared_mutex_attribute &) = delete;
#else // !( __cplusplus >= 201103L )
private:
	shared_mutex_attribute(const shared_mutex_attribute &);
	shared_mutex_attribute &operator =(const shared_mutex_attribute &);
public:
#endif // __cplusplus >= 201103L

	void set_process_shared(bool pshared = true)
	{
		int err = pthread_rwlockattr_setpshared(&attr_, 
			(pshared ? PTHREAD_PROCESS_SHARED : PTHREAD_PROCESS_PRIVATE));
		if (err != 0) {
			throw system_error(err, system_category(), __func__);
		}
	}

	bool is_process_shared() const noexcept
	{
		int pshared;
		int err = pthread_rwlockattr_getpshared((pthread_rwlockattr_t *) &attr_, &pshared);
		(void) err;
		assert(err == 0);
		return (pshared == PTHREAD_PROCESS_SHARED);
	}

	/** 
	 * Returns the underlying implementation-defined native handle object. 
	 */
	native_handle_type native_handle() noexcept { return &attr_; }
	const_native_handle_type native_handle() const noexcept { return &attr_; }
};

} // namespace Hx

#endif // HX_SHARED_MUTEX_ATTRIBUTE_H
