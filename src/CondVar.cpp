//
// CondVar.cpp for LibNet in /home/alexmog/projets/LibNet/src
// 
// Made by Moghrabi Alexandre
// Login   <alexandre.moghrabi@epitech.eu>
// 
// Started on  Tue Nov 11 19:48:17 2014 Moghrabi Alexandre
// Last update Tue Nov 11 19:55:49 2014 Moghrabi Alexandre
//

#include "ThreadException.hh"
#include "CondVar.hh"

namespace mognetwork
{
  CondVar::CondVar()
  {
    if (pthread_cond_init(&m_cond, NULL) != 0)
      throw ThreadException("pthread_cond_init error.", __LINE__, __FILE__);
  }

  CondVar::~CondVar()
  {
    if (pthread_cond_destroy(&m_cond) != 0)
      throw ThreadException("pthread_cond_destroy error.", __LINE__, __FILE__);
  }

  void CondVar::wait()
  {
    if (pthread_cond_wait(&m_cond, &m_mutex) != 0)
      throw ThreadException("pthread_cond_wait error.", __LINE__, __FILE__);
  }

  void CondVar::signal()
  {
    if (pthread_cond_signal(&m_cond) != 0)
      throw ThreadException("pthread_cond_signal error.", __LINE__, __FILE__);
  }

  void CondVar::broadcast()
  {
    if (pthread_cond_broadcast(&m_cond) != 0)
      throw ThreadException("pthread_cond_broadcast error.", __LINE__, __FILE__);
  }

  void CondVar::timedwait(const struct timespec* abstime)
  {
    if (pthread_cond_timedwait(&m_cond, &m_mutex, abstime) != 0)
      throw ThreadException("pthread_cond_timedwait error.", __LINE__, __FILE__);
  }
}; // namespace mognetwork
