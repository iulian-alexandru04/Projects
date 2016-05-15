package com.imc.spring.configuration;

import java.util.Properties;

import javax.sql.DataSource;

import org.hibernate.SessionFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.PropertySource;
import org.springframework.core.env.Environment;
import org.springframework.jdbc.datasource.DriverManagerDataSource;
import org.springframework.orm.hibernate4.HibernateTransactionManager;
import org.springframework.orm.hibernate4.LocalSessionFactoryBean;
import org.springframework.transaction.annotation.EnableTransactionManagement;

@Configuration
@EnableTransactionManagement
@ComponentScan({ "com.imc.spring" })
@PropertySource(value = { "classpath:database.properties" })
public class HibernateConfiguration {

	@Autowired
	private Environment env;

	@Bean
	public DataSource dataSource() {
		DriverManagerDataSource dmds = new DriverManagerDataSource();
		dmds.setDriverClassName(env.getRequiredProperty("jdbc.driverClassName"));
		dmds.setUrl(env.getRequiredProperty("jdbc.url"));
		dmds.setUsername(env.getRequiredProperty("jdbc.username"));
		dmds.setPassword(env.getRequiredProperty("jdbc.password"));
		return dmds;
	}

	private Properties hibernateProperties() {
		Properties prop = new Properties();
		prop.put("hibernate.dialect", env.getRequiredProperty("hibernate.dialect"));
		// env with getrequiredproperty read fro classpath:database.properties
		prop.put("hibernate.show_sql", env.getRequiredProperty("hibernate.show_sql"));
		prop.put("hibernate.format_sql", env.getRequiredProperty("hibernate.format_sql"));
		return prop;
	}

	@Bean
	public LocalSessionFactoryBean sessionFactory() {
		LocalSessionFactoryBean sessionFactory = new LocalSessionFactoryBean();
		sessionFactory.setDataSource(dataSource());
		sessionFactory.setPackagesToScan(env.getRequiredProperty("packages"));
		sessionFactory.setHibernateProperties(hibernateProperties());
		return sessionFactory;
	}

	@Bean
	@Autowired
	public HibernateTransactionManager transactionManager(SessionFactory sf) {
		HibernateTransactionManager manager = new HibernateTransactionManager();
		manager.setSessionFactory(sf);
		return manager;
	}
}